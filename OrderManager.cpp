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
			data.items,
			data.payments,
			data.customer
		};

		array<Object^>^ result_array = this->dbCreateRow(Components::Table::getOrderTable(), array_data);
		data.id = Convert::ToInt32(result_array[0]);
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