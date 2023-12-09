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

	private:
		float computeForAllProducts(float (*operation) (DataRow^));
		static float getProductCommercialValue(DataRow^ product_row);
		static float getProductPurchaseValue(DataRow^ product_row);
	};

}

