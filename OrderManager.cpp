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
			data.customer
		};

		array<Object^>^ result_array = this->dbCreateRow(Components::Table::getOrderTable(), array_data);
		data.id = Convert::ToInt32(result_array[0]);

		for each (OrderItem items in data.items) {
			array<Object^>^ items_array = gcnew array<Object^> {
				items.product.ref,
			};
			DataTable^ found = this->dbSearchRows(Components::Table::getOrderTable(), gcnew array<String^>{"Reference_Article"}, items_array);
			DataRow^ item_row = found->Rows[0];
			int id_item = Convert::ToInt32(item_row->ItemArray[0]);

			array<Object^>^ order_array = gcnew array<Object^> {
				items.product.ref,
				items.productCount, 
				items.discountRatio, 
				items.TaxRatio, 
				items.UHTPrice, 
				id_item, 
				data.id,
			};
			this->dbCreateRow(Components::Table::getContainsTable(), order_array);
		}

		for each (Payment payments in data.payments) {
			array<Object^>^ paiement_array = gcnew array<Object^> {
				payments.mean,
				payments.receptionDate,
				payments.paymentDate,
				data.id,
			};
			this->dbCreateRow(Components::Table::getPaymentTable(), paiement_array);
		}
		return data;
	}

	OrderData OrderManager::getOrder(int id)
	{
		array<Object^>^ result_array = this->dbReadRow(Components::Table::getOrderTable(), id);
		OrderData result;
		if (result_array->Length != 5)
			return result;

		result.id = id;
		result.deliveryDate = safe_cast<MySqlDateTime>(result_array[0]);
		result.emissionDate = safe_cast<MySqlDateTime>(result_array[1]);
		result.items =  safe_cast<array<OrderItem>^>(result_array[2]);
		result.payments = safe_cast<array<Payment>^>(result_array[3]);
		result.customer = safe_cast<CustomerData>(result_array[4]);
		return result;
	}

	OrderData OrderManager::editOrder(int id, OrderData _new)
	{
		array<Object^>^ input_array = gcnew array<Object^> {
			_new.ref,
			_new.deliveryDate,
			_new.emissionDate,
			_new.items,
			_new.payments,
			_new.customer,
		};
		this->dbUpdateRow(Components::Table::getOrderTable(), input_array, id);
		_new.id = id;
		return _new;
	}

	void OrderManager::removeOrder(int id)
	{
		this->dbDeleteRow(Components::Table::getOrderTable(), id);
	}

	
}