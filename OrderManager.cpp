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
			data.customer.id
		};

		array<Object^>^ result_array = this->dbCreateRow(Components::Table::getOrderTable(), array_data);
		data.id = Convert::ToInt32(result_array[0]);

		for each (OrderItem items in data.items) {
			array<Object^>^ items_array = gcnew array<Object^> {
				items.product.ref,
			};
			DataTable^ found = this->dbSearchRows(Components::Table::getProductTable(), gcnew array<String^>{"Reference_Article"}, items_array);
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
			String^ mean_str = "<Inconnu>";
			switch (payments.mean) {
			case PaymentMean::CreditCard:
				mean_str = "CB";
				break;
			case PaymentMean::Cash:
				mean_str = "Espèces";
				break;
			}

			array<Object^>^ paiement_array = gcnew array<Object^> {
				mean_str,
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
		array<Object^>^ order_array = this->dbReadRow(Components::Table::getOrderTable(), id);
		OrderData result = OrderData();
		if (order_array->Length != 5)
			return result;

		DataTable^ found_items = this->dbSearchRows(Components::Table::getContainsTable(),
			gcnew array<String^>{"ID_Commande"}, gcnew array<Object^>{id}
		);
		List<OrderItem>^ order_items = gcnew List<OrderItem>();
		for each (DataRow^ item_row in found_items->Rows) {
			int product_id = Convert::ToInt32(item_row->ItemArray[1]);

			array<Object^>^ product_array = this->dbReadRow(Components::Table::getProductTable(), product_id);

			OrderItem item = OrderItem();
			item.product = ProductData();
			item.product.ref = product_id;
			item.product.name = Convert::ToString(product_array[1]);
			item.product.priceNoTax = (float)Convert::ToDecimal(product_array[2]);
			item.product.purchaseValue = (float)Convert::ToDecimal(product_array[3]);
			item.product.amount = Convert::ToInt32(product_array[4]);
			item.product.TVARatio = (float)Convert::ToDecimal(product_array[5]);
			item.product.discountRatio = (float)Convert::ToDecimal(product_array[6]);
			item.product.restockThreshold = Convert::ToInt32(product_array[7]);

			item.productCount = Convert::ToInt32(item_row->ItemArray[2]);
			item.discountRatio = (float)Convert::ToDecimal(item_row->ItemArray[3]);
			item.TaxRatio = (float)Convert::ToDecimal(item_row->ItemArray[4]);
			item.UHTPrice = (float)Convert::ToDecimal(item_row->ItemArray[5]);

			order_items->Add(item);
		}
		DataTable^ found_payments = this->dbSearchRows(Components::Table::getPaymentTable(),
			gcnew array<String^>{"ID_Commande"}, gcnew array<Object^>{id}
		);
		List<Payment>^ payments = gcnew List<Payment>();
		for each (DataRow^ payment_row in found_payments->Rows) {
			String^ payment_mean = Convert::ToString(payment_row->ItemArray[1]);

			Payment payment = Payment();
			payment.mean = PaymentMean::CreditCard;
			if (payment_mean->Equals("CB")) {
				payment.mean = PaymentMean::CreditCard;
			}
			payment.receptionDate = safe_cast<DateTime^>(payment_row->ItemArray[2]);
			payment.paymentDate = safe_cast<DateTime^>(payment_row->ItemArray[3]);
			payments->Add(payment);
		}

		result.id = id;
		result.deliveryDate = safe_cast<DateTime^>(order_array[0]);
		result.emissionDate = safe_cast<DateTime^>(order_array[1]);
		result.items = order_items->ToArray();
		result.payments = payments->ToArray();
		result.customer = safe_cast<CustomerData>(order_array[4]);
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