#pragma once
#include "SupplyManager.h"
#include "CustomerManager.h"
#include "OrderManager.h"
#include "StaffManager.h"

namespace Services {

	ref class StatsProvider
	{
		SupplyManager^ supply;
		CustomerManager^ customers;
		OrderManager^ orders;
		StaffManager^ staff;

	public:
		StatsProvider(SupplyManager^ supply, CustomerManager^ customers, OrderManager^ orders, StaffManager^ staff);
		float computeAvgBasket();
		float computeMonthlySales();
		array<ProductData>^ findProductsThatNeedRestock();
		float computeClientTotalPurchase(CustomerData customer);
		array<ProductData>^ find10BestSellers();
		array<ProductData>^ find10WorstSellers();
		float computeStockCommercialValue();
		float computeStockPurchaseValue();
		float simulateCommercialValue(float TVA, float commercialMargin, float commercialDiscount, float unknownMark);
	};

}

