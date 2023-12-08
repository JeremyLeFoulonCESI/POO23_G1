#pragma once
#include "Manager.h"
#include "Struct.h"

using namespace structure;

namespace Services {
	ref class OrderManager : public Manager
	{
	public:
		OrderManager();

		OrderData addOrder(OrderData data);
		OrderData getOrder(int id);
		OrderData editOrder(int id, OrderData _new);
		void removeOrder(int id);
		DataTable^ getAllOrders();
	};
}
