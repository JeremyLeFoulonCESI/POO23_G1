#include "pch.h"
#include "SupplyManager.h"


namespace Services {
	SupplyManager::SupplyManager() :
		Manager()
	{}

	ProductData SupplyManager::addProduct(ProductData data) {
		array<Object^>^ array_data = gcnew array<Object^>{
			data.name,
			data.priceNoTax,
			data.purchaseValue,
			data.amount,
			data.TVARatio,
			data.discountRatio,
			data.restockThreshold
		};
		this->dbOpenConnection();
		array<Object^>^ result_array = this->dbCreateRow(Components::Table::getProductTable(), array_data);
		data.ref = Convert::ToInt32(result_array[0]);
		this->dbCloseConnection();
		return data;
	}
	ProductData SupplyManager::getProduct(int id) {
		this->dbOpenConnection();
		array<Object^>^ result_array = this->dbReadRow(Components::Table::getProductTable(), id);
		ProductData result;
		if (result_array->Length != 7)
			return result;
		this->dbCloseConnection();
		result.ref = id;
		result.name = Convert::ToString(result_array[0]);
		result.priceNoTax = (float)Convert::ToDecimal(result_array[1]);
		result.purchaseValue = (float)Convert::ToDecimal(result_array[2]);
		result.amount = Convert::ToInt32(result_array[3]);
		result.TVARatio = (float)Convert::ToDecimal(result_array[4]);
		result.discountRatio = (float)Convert::ToDecimal(result_array[5]);
		result.restockThreshold = Convert::ToInt32(result_array[6]);
		return result;
	}

	ProductData SupplyManager::editProduct(int id, ProductData _new) {
		array<Object^>^ input_array = gcnew array<Object^> {
			_new.name,
			_new.priceNoTax,
			_new.purchaseValue,
			_new.amount,
			_new.TVARatio,
			_new.discountRatio,
			_new.restockThreshold
		};
		this->dbOpenConnection();
		this->dbUpdateRow(Components::Table::getProductTable(), input_array, id);
		_new.ref = id;
		this->dbCloseConnection();
		return _new;
	}
	void SupplyManager::removeProduct(int id) {
		this->dbOpenConnection();
		this->dbDeleteRow(Components::Table::getProductTable(), id);
		this->dbCloseConnection();
	}

	DataTable^ SupplyManager::getAllProducts() {
		this->dbOpenConnection();
		DataTable^ raw_products = this->readAll(Components::Table::getProductTable());

		DataTable^ result = gcnew DataTable;
		result->Columns->AddRange(gcnew array<DataColumn^>{
			gcnew DataColumn("Référence"),
			gcnew DataColumn("Nom"),
			gcnew DataColumn("Prix UHT"),
			gcnew DataColumn("Valeur d'achat"),
			gcnew DataColumn("Quantité en stock"),
			gcnew DataColumn("Taux de la TVA en %"),
			gcnew DataColumn("Taux de réduction en %"),
			gcnew DataColumn("Seuil de réapprovisionnment")
		});

		for each (DataRow ^ row in raw_products->Rows) {
			if (Convert::ToInt32(row->ItemArray[4]) < 0)
				continue;

			result->Rows->Add(
				row->ItemArray[0], 
				row->ItemArray[1], 
				row->ItemArray[2], 
				row->ItemArray[3], 
				row->ItemArray[4], 
				gcnew Int32((float)Convert::ToDecimal(row->ItemArray[5]) * 100),
				gcnew Int32((float)Convert::ToDecimal(row->ItemArray[6]) * 100),
				row->ItemArray[7]
			);
		}
		this->dbCloseConnection();
		return result;
	}
}

