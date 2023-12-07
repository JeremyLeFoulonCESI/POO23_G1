#include "pch.h"
#include "OrderManager.h"

namespace Services {
	
	OrderManager::OrderManager() :
		Manager()
	{}

	OrderData OrderManager::addOrder(OrderData data)
	{

		array<Object^>^ array_data = gcnew array<Object^>{
			data.ref,
			data.deliveryDate,
			data.emissionDate,
			data.customer.id
		};

		this->dbOpenConnection();
		array<Object^>^ result_array = this->dbCreateRow(Components::Table::getOrderTable(), array_data);
		data.id = Convert::ToInt32(result_array[0]);

		for each (OrderItem item in data.items) {
			DataTable^ found = this->dbSearchRows(
				Components::Table::getProductTable(), 
				gcnew array<String^>{"Reference_Article"}, 
				gcnew array<Object^>{data.id}
			);

			array<Object^>^ item_array = gcnew array<Object^> {
				data.id,
				item.product.ref,
				item.productCount,
				item.product.discountRatio, 
				item.product.TVARatio, 
				item.product.priceNoTax
			};
			this->dbCreateRow(Components::Table::getContainsTable(), item_array);
		}

		for each (Payment payments in data.payments) {
			String^ mean_str = "<Inconnu>";
			switch (payments.mean) {
			case PaymentMean::CreditCard:
				mean_str = "CB";
				break;
			case PaymentMean::Cash:
				mean_str = "Espèces";
				break;
			}

			array<Object^>^ paiement_array = gcnew array<Object^> {
				mean_str,
				payments.receptionDate,
				payments.paymentDate,
				data.id,
			};
			this->dbCreateRow(Components::Table::getPaymentTable(), paiement_array);
		}
		this->dbCloseConnection();
		return data;
	}

	OrderData OrderManager::getOrder(int id)
	{
		this->dbOpenConnection();
		array<Object^>^ order_array = this->dbReadRow(Components::Table::getOrderTable(), id);
		OrderData result = OrderData();
		if (order_array->Length != 5)
			return result;

		DataTable^ found_items = this->dbSearchRows(Components::Table::getContainsTable(),
			gcnew array<String^>{"ID_Commande"}, gcnew array<Object^>{id}
		);
		List<OrderItem>^ order_items = gcnew List<OrderItem>();
		for each (DataRow^ item_row in found_items->Rows) {
			int product_id = Convert::ToInt32(item_row->ItemArray[1]);

			array<Object^>^ product_array = this->dbReadRow(Components::Table::getProductTable(), product_id);

			OrderItem item = OrderItem();
			item.product = ProductData();
			item.product.ref = product_id;
			item.product.name = Convert::ToString(product_array[1]);
			item.product.priceNoTax = (float)Convert::ToDecimal(product_array[2]);
			item.product.purchaseValue = (float)Convert::ToDecimal(product_array[3]);
			item.product.amount = Convert::ToInt32(product_array[4]);
			item.product.TVARatio = (float)Convert::ToDecimal(product_array[5]);
			item.product.discountRatio = (float)Convert::ToDecimal(product_array[6]);
			item.product.restockThreshold = Convert::ToInt32(product_array[7]);

			item.productCount = Convert::ToInt32(item_row->ItemArray[2]);
			item.discountRatio = (float)Convert::ToDecimal(item_row->ItemArray[3]);
			item.TaxRatio = (float)Convert::ToDecimal(item_row->ItemArray[4]);
			item.UHTPrice = (float)Convert::ToDecimal(item_row->ItemArray[5]);

			order_items->Add(item);
		}
		DataTable^ found_payments = this->dbSearchRows(Components::Table::getPaymentTable(),
			gcnew array<String^>{"ID_Commande"}, gcnew array<Object^>{id}
		);
		this->dbCloseConnection();
		List<Payment>^ payments = gcnew List<Payment>();
		for each (DataRow^ payment_row in found_payments->Rows) {
			String^ payment_mean = Convert::ToString(payment_row->ItemArray[1]);

			Payment payment = Payment();
			payment.mean = PaymentMean::CreditCard;
			if (payment_mean->Equals("CB")) {
				payment.mean = PaymentMean::CreditCard;
			}
			payment.receptionDate = safe_cast<DateTime^>(payment_row->ItemArray[2]);
			payment.paymentDate = safe_cast<DateTime^>(payment_row->ItemArray[3]);
			payments->Add(payment);
		}

		result.id = id;
		result.deliveryDate = safe_cast<DateTime^>(order_array[0]);
		result.emissionDate = safe_cast<DateTime^>(order_array[1]);
		result.items = order_items->ToArray();
		result.payments = payments->ToArray();
		result.customer = safe_cast<CustomerData>(order_array[4]);
		return result;
	}

	OrderData OrderManager::editOrder(int id, OrderData _new)
	{
		this->dbOpenConnection();
		DataTable^ found_items = this->dbSearchRows(
			Components::Table::getContainsTable(),
			gcnew array<String^>{ "ID_Commande" },
			gcnew array<Object^>{ id }
		);
		for each (OrderItem item in _new.items) {
			array<Object^>^ item_array = gcnew array<Object^> {
				id, 
				item.product.ref, 
				item.productCount, 
				item.product.discountRatio, 
				item.product.TVARatio, 
				item.product.priceNoTax
			};
			this->dbCreateRow(Components::Table::getContainsTable(), item_array);
		}

		for each (DataRow^ item_row in found_items->Rows) {
			int item_product_id = Convert::ToInt32(item_row->ItemArray[1]);
			this->dbDeleteRow(Components::Table::getContainsTable(), id, item_product_id);
		}

		DataTable^ found_payments = this->dbSearchRows(
			Components::Table::getPaymentTable(),
			gcnew array<String^> { "ID_Commande" },
			gcnew array<Object^> { id }
		);
		for each (Payment payment in _new.payments) {

			String^ mean_str = "<Inconnu>";
			switch (payment.mean) {
			case PaymentMean::CreditCard:
				mean_str = "CB";
				break;
			case PaymentMean::Cash:
				mean_str = "Espèces";
				break;
			}

			array<Object^>^ paiement_array = gcnew array<Object^> {
				mean_str,
					payment.receptionDate,
					payment.paymentDate,
					id,
			};
			this->dbCreateRow(Components::Table::getPaymentTable(), paiement_array);
		}
		for each (DataRow^ payment_row in found_items->Rows) {
			int payment_id = Convert::ToInt32(payment_row->ItemArray[0]);
			this->dbDeleteRow(Components::Table::getPaymentTable(), id);
		}


		array<Object^>^ order_array = gcnew array<Object^> {
			_new.ref,
			_new.deliveryDate,
			_new.emissionDate,
			_new.customer.id
		};
		this->dbUpdateRow(Components::Table::getOrderTable(), order_array, id);
		this->dbCloseConnection();
		_new.id = id;
		return _new;
	}

	void OrderManager::removeOrder(int id)
	{
		this->dbOpenConnection();
		DataTable^ found_items = this->dbSearchRows(
			Components::Table::getContainsTable(),
			gcnew array<String^>{ "ID_Commande" },
			gcnew array<Object^>{ id }
		);
		for each (DataRow ^ item_row in found_items->Rows) {
			int item_product_id = Convert::ToInt32(item_row->ItemArray[1]);
			this->dbDeleteRow(Components::Table::getContainsTable(), id, item_product_id);
		}

		DataTable^ found_payments = this->dbSearchRows(
			Components::Table::getPaymentTable(),
			gcnew array<String^> { "ID_Commande" },
			gcnew array<Object^> { id }
		);
		for each (DataRow ^ payment_row in found_items->Rows) {
			int payment_id = Convert::ToInt32(payment_row->ItemArray[0]);
			this->dbDeleteRow(Components::Table::getPaymentTable(), id);
		}

		this->dbDeleteRow(Components::Table::getOrderTable(), id);
		this->dbCloseConnection();
	}

	DataTable^ OrderManager::getAllOrders() {
		DataTable^ result = gcnew DataTable;
		result->Columns->AddRange(gcnew array<DataColumn^>{
			gcnew DataColumn("Client (Nom Prénom - Tél.)"),
			gcnew DataColumn("Référence"),
			gcnew DataColumn("Date de livraison"),
			gcnew DataColumn("Date d'émission"),
			gcnew DataColumn("Paiments (Moyen-DateEncaissement-DateEmission)"),
			gcnew DataColumn("Articles (Nombre x Nom: PrixHT en €)"),
			gcnew DataColumn("Montant total HT en €"),
			gcnew DataColumn("Montant total TVA en €"),
			gcnew DataColumn("Montant total TTC en €")
		});
		this->dbOpenConnection();
		DataTable^ all_orders = this->readAll(Components::Table::getOrderTable());

		for each (DataRow^ order_row in all_orders->Rows) {
			float ht_total = 0;
			float tva_total = 0;
			float ttc_total = 0;

			array<Object^>^ order_array = order_row->ItemArray;

			int order_id = Convert::ToInt32(order_array[0]);
			int customer_code = Convert::ToInt32(order_array[4]);

			DataTable^ items_dt = this->dbSearchRows(
				Components::Table::getContainsTable(),
				gcnew array<String^>{ "ID_Commande" },
				gcnew array<Object^>{ order_id }
			);

			DataTable^ payments_dt = this->dbSearchRows(
				Components::Table::getPaymentTable(),
				gcnew array<String^>{ "ID_Commande" },
				gcnew array<Object^>{ order_id }
			);

			String^ items_str = "";
			
			for each (DataRow^ item_row in items_dt->Rows) {
				int product_id = Convert::ToInt32(item_row->ItemArray[1]);
				int product_count = Convert::ToInt32(item_row->ItemArray[2]);
				float tvaRatio = (float)Convert::ToDecimal(item_row->ItemArray[4]);
				float priceUHT = (float)Convert::ToDecimal(item_row->ItemArray[5]);

				array<Object^>^ product_array = this->dbReadRow(Components::Table::getProductTable(), product_id);
				String^ product_name = Convert::ToString(product_array[1]);

				ht_total += priceUHT * product_count;
				tva_total += tvaRatio * priceUHT * product_count;
				ttc_total += priceUHT * (1 + tvaRatio) * product_count;

				items_str += product_count + "x " + product_name + ": " + (priceUHT * product_count) + ";";
			}
			if (items_str->EndsWith(";")) {
				items_str = items_str->Remove(items_str->Length - 1, 1);
			}

			String^ payments_str = "";

			for each (DataRow^ payment_row in payments_dt->Rows) {
				String^ mean_str = Convert::ToString(payment_row->ItemArray[1]);
				DateTime^ receptionDate = safe_cast<DateTime^>(payment_row->ItemArray[2]);
				DateTime^ paymentDate = safe_cast<DateTime^>(payment_row->ItemArray[3]);

				payments_str += mean_str + "-" + receptionDate->Day + "." + receptionDate->Month + "." + receptionDate->Year;
				payments_str += "-" + paymentDate->Day + "." + paymentDate->Month + "." + paymentDate->Year + ";";
			}
			if (payments_str->EndsWith(";")) {
				payments_str = payments_str->Remove(payments_str->Length - 1, 1);
			}

			String^ reference = Convert::ToString(order_array[1]);
			DateTime^ deliveryDate = safe_cast<DateTime^>(order_array[2]);
			DateTime^ emissionDate = safe_cast<DateTime^>(order_array[3]);

			String^ dDate_str = deliveryDate->Day + "." + deliveryDate->Month + "." + deliveryDate->Year;
			String^ eDate_str = emissionDate->Day + "." + emissionDate->Month + "." + emissionDate->Year;

			array<Object^>^ array_customer = this->dbReadRow(
				Components::Table::getCustomerTable(), customer_code
			);
			String^ customer_lname = Convert::ToString(array_customer[1]);
			String^ customer_fname = Convert::ToString(array_customer[2]);
			String^ customer_phone = Convert::ToString(array_customer[5]);

			String^ customer_str = customer_lname + " " + customer_fname + " - " + customer_phone;

			result->Rows->Add(customer_str, reference, dDate_str, eDate_str, payments_str, items_str, ht_total, tva_total, ttc_total);
		}
		this->dbCloseConnection();
		return result;
	}
	
}