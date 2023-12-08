#pragma once
#include "Manager.h"
#include "DataAccessor.h"

namespace Services {

	ref class StatsProvider : public Manager
	{

	public:
		StatsProvider();
		float computeAvgBasket();
		float computeMonthlySales(int* count);
		DataTable^ findProductsThatNeedRestock();
		float computeClientTotalPurchase(CustomerData customer);
		DataTable^ find10BestSellers();
		DataTable^ find10WorstSellers();
		float computeStockCommercialValue();
		float computeStockPurchaseValue();
		float simulateCommercialValue(float TVA, float commercialMargin, float commercialDiscount, float unknownMark);
	};

}

