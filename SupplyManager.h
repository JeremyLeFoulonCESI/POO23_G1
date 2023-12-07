#pragma once
#include "Manager.h"
#include "Struct.h"


using namespace structure;

namespace Services {
	ref class SupplyManager : public Manager
	{
	public:
		SupplyManager();

		ProductData addProduct(ProductData data);
		ProductData getProduct(int id);
		ProductData editProduct(int id, ProductData _new);
		void removeProduct(int id);
		DataTable^ getAllProducts();
	};
}

