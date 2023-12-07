#pragma once
#include "Manager.h"
#include "Struct.h"

using namespace System;
using namespace System::Data;
using namespace structure;


namespace Services {

	ref class CustomerManager : public Manager
	{
	public:
		CustomerManager();
		CustomerData addCustomer(CustomerData data);
		CustomerData getCustomer(int id);
		CustomerData editCustomer(int id, CustomerData _new);
		void removeCustomer(int id);
		DataTable^ getAllCustomers();
	};

}

