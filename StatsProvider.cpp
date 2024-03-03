#include "pch.h"
#include "StatsProvider.h"


namespace Services {
	StatsProvider::StatsProvider()
	{}

	float StatsProvider::computeMonthlySales(int month, int* count) {
		float total_sales = 0;
		if (count) *count = 0;

		this->dbOpenConnection();
		for each (DataRow ^ order_row in this->readAll(Components::Table::getOrderTable())->Rows) {
			int order_id = Convert::ToInt32(order_row->ItemArray[0]);
			DateTime^ emitDate = safe_cast<DateTime^>(order_row->ItemArray[3]);

			if (count) (*count)++;

			for each (DataRow ^ contains_row in this->dbSearchRows(
				Components::Table::getContainsTable(),
				gcnew array<String^>{ "ID_Commande" },
				gcnew array<Object^>{ order_id }
			)->Rows) {
				float UHTprice = (float)Convert::ToDecimal(contains_row->ItemArray[5]);
				float TVA = (float)Convert::ToDecimal(contains_row->ItemArray[4]);
				float discount = (float)Convert::ToDecimal(contains_row->ItemArray[3]);
				int amount = Convert::ToInt32(contains_row->ItemArray[2]);

				total_sales += UHTprice * (1 - discount) * (float)amount;
			}
		}
		this->dbCloseConnection();
		return total_sales;
	}


	float StatsProvider::computeAvgBasket() {
		int totalOrders = 0;
		float totalSales = 0;

		// Calculer le panier moyen pour chaque mois de l'année (1 à 12)
		for (int month = 1; month <= 12; ++month) {
			int count = 0;
			float monthlySales = this->computeMonthlySales(month, &count);
			totalSales += monthlySales;
			totalOrders += count;
		}

		// Vérifier si le nombre total de commandes est différent de zéro pour éviter une division par zéro
		if (totalOrders != 0) {
			return totalSales / totalOrders;
		}
		else {
			// Si le nombre total de commandes est zéro, retourner zéro pour éviter une division par zéro
			return 0;
		}
	}

	
	DataTable^ StatsProvider::findProductsThatNeedRestock() {
		DataTable^ result = gcnew DataTable;
		result->Columns->AddRange(gcnew array<DataColumn^>{
			gcnew DataColumn("Référence"),
			gcnew DataColumn("Nom"),
			gcnew DataColumn("Quantité"),
			gcnew DataColumn("Seuil de réapprovisionnement")
		});

		this->dbOpenConnection();
		for each (DataRow^ product_row in this->readAll(Components::Table::getProductTable())->Rows) {
			int amount = Convert::ToInt32(product_row->ItemArray[4]);
			int restock = Convert::ToInt32(product_row->ItemArray[7]);

			if ((amount > restock) || (amount < 0))
				continue;

			result->Rows->Add(
				product_row->ItemArray[0],
				product_row->ItemArray[1],
				product_row->ItemArray[4],
				product_row->ItemArray[7]
			);
		}

		this->dbCloseConnection();
		return result;
	}
	float StatsProvider::computeClientTotalPurchase(CustomerData customer) {
		float total_purchase = 0;

		this->dbOpenConnection();
		customer.id = -1; // Initialisation à une valeur impossible
		// Recherche de l'ID du client à partir du nom et du prénom
		for each (DataRow ^ customer_row in this->dbSearchRows(
			Components::Table::getCustomerTable(),
			gcnew array<String^>{"Nom", "Prenom"},
			gcnew array<Object^>{customer.lastName, customer.firstName}
			)->Rows) {
			customer.id = Convert::ToInt32(customer_row->ItemArray[0]);
			break; // Nous ne voulons que la première correspondance, donc nous sortons de la boucle après avoir trouvé le client
			}

		// Vérification si le client existe
		if (customer.id == -1) {
			// Le client n'existe pas, retourner 0 pour les achats totaux
			this->dbCloseConnection();
			return 5;
		}

		// Parcourir les commandes du client correspondant
		for each (DataRow ^ order_row in this->dbSearchRows(
			Components::Table::getOrderTable(),
			gcnew array<String^>{"CodeClient"},
			gcnew array<Object^>{customer.id}
		)->Rows) {
			int order_id = Convert::ToInt32(order_row->ItemArray[0]);

			// Calcul du montant total pour chaque commande
			for each (DataRow ^ contains_row in this->dbSearchRows(
				Components::Table::getContainsTable(),
				gcnew array<String^>{"ID_Commande"},
				gcnew array<Object^>{order_id}
			)->Rows) {
				float UHTprice = (float)Convert::ToDecimal(contains_row->ItemArray[5]);
				float TVA = (float)Convert::ToDecimal(contains_row->ItemArray[4]);
				float discount = (float)Convert::ToDecimal(contains_row->ItemArray[3]);
				int count = Convert::ToInt32(contains_row->ItemArray[2]);

				total_purchase += (UHTprice * (1 + TVA) * (1 - discount)) * count;
			}
		}
		this->dbCloseConnection();
		return total_purchase;
	}


	DataTable^ StatsProvider::find10BestSellers() {
		this->dbOpenConnection();
		DataTable^ result = this->runRawQuery(Components::DataAccessor::best_sellers());
		this->dbCloseConnection();
		return result;
	}
	DataTable^ StatsProvider::find10WorstSellers() {
		this->dbOpenConnection();
		DataTable^ result = this->runRawQuery(Components::DataAccessor::worst_sellers());
		this->dbCloseConnection();
		return result;
	}
	float StatsProvider::computeStockCommercialValue() {
		return this->computeForAllProducts(gcnew ProductInfoProvider(&StatsProvider::getProductCommercialValue));
	}
	float StatsProvider::computeStockPurchaseValue() {
		return this->computeForAllProducts(gcnew ProductInfoProvider(&StatsProvider::getProductPurchaseValue));
	}
	float StatsProvider::computeForAllProducts(ProductInfoProvider^ operation) {
		float total = 0;
		this->dbOpenConnection();
		for each (DataRow^ product_row in this->readAll(Components::Table::getProductTable())->Rows) {
			if (operation) {
				float value = operation(product_row);
				total += value;
			}
		}
		this->dbCloseConnection();
		return total;
	}
	float StatsProvider::getProductCommercialValue(DataRow^ product_row) {
		float UHTprice = (float)Convert::ToDecimal(product_row->ItemArray[2]);
		int count = Convert::ToInt32(product_row->ItemArray[4]);
		float TVA = (float)Convert::ToDecimal(product_row->ItemArray[5]);
		float discount = (float)Convert::ToDecimal(product_row->ItemArray[6]);
		return UHTprice * (1 + TVA) * (1 - discount) * (float)count;
	}
	float StatsProvider::getProductPurchaseValue(DataRow^ product_row) {
		float UAprice = (float)Convert::ToDecimal(product_row->ItemArray[3]);
		int count = Convert::ToInt32(product_row->ItemArray[4]);
		return UAprice * (float)count;
	}
	float StatsProvider::simulateCommercialValue(float TVA, float commercialMargin, float commercialDiscount, float shrink) {
		float result = 0;
		
		this->dbOpenConnection();
		for each (DataRow^ product_row in this->readAll(Components::Table::getProductTable())->Rows) {
			float UHTprice = (float)Convert::ToDecimal(product_row->ItemArray[2]);
			int count = Convert::ToInt32(product_row->ItemArray[4]);

			float real_count = count * (1 - shrink);

			float real_value = UHTprice * (1 + TVA) * (1 + commercialMargin) * (1 - commercialDiscount);
			result += real_value * real_count;
		}
		this->dbCloseConnection();

		return result;
	}
	
}

