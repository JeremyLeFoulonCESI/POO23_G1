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

		array<Object^>^ result_array = this->dbCreateRow(Components::Table::getProductTable(), array_data);
		data.ref = Convert::ToInt32(result_array[0]);
		return data;
	}
	ProductData SupplyManager::getProduct(int id) {
		array<Object^>^ result_array = this->dbReadRow(Components::Table::getProductTable(), id);
		ProductData result;
		if (result_array->Length != 7)
			return result;
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
		this->dbUpdateRow(Components::Table::getProductTable(), input_array, id);
		_new.ref = id;
		return _new;
	}
	void SupplyManager::removeProduct(int id) {
		this->dbDeleteRow(Components::Table::getProductTable(), id);
	}
}

