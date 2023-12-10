#pragma once

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace MySql::Data::Types;

namespace structure {
	public value struct Column {
	public:
		String^ name;
		Object^ value;
	};

	public value struct Address {
	public:
		String^ streetNum;
		String^ streetName;
		String^ cityName;
		String^ cityCode;
		String^ ToString() override;
	};

	public value struct StaffMemberData {
	public:
		int id;
		String^ firstName;
		String^ lastName;
		DateTime^ hireDate;
		int superior;
		Address address;
	};

	public value struct CustomerData {
	public:
		int id;
		String^ firstName;
		String^ lastName;
		DateTime^ birth;
		String^ email;
		String^ phoneNumber;
		DateTime^ firstPurchase;
		array<Address>^ invoiceAdresses;
		array<Address>^ deliveryAddresses;
	};

	public value struct ProductData {
	public:
		int ref;
		String^ name;
		float priceNoTax;
		float purchaseValue;
		int amount;
		float TVARatio;
		float discountRatio;
		int restockThreshold;

		String^ ToString() override;
	};

	public value struct OrderItem {
	public:
		ProductData product;
		int productCount;
		float discountRatio;
		float TaxRatio;
		float UHTPrice;
		String^ ToString() override;
	};

	public enum class PaymentMean {
		CreditCard,
		Cash
	};

	public value struct Payment {
	public:
		PaymentMean mean;
		DateTime^ receptionDate;
		DateTime^ paymentDate;
		String^ ToString() override;
	};

	public value struct OrderData {
	public:
		int id;
		String^ ref;
		DateTime^ deliveryDate;
		DateTime^ emissionDate;
		array<OrderItem>^ items;
		array<Payment>^ payments;
		CustomerData customer;
	};
	
	public value struct StaffSelector_Row {
		String^ lname;
		String^ fname;
		int id;

		String^ ToString() override;
	};

	public value struct CustomerSelector_Row {
		String^ lname;
		String^ fname;
		String^ phone;
		int id;

		String^ ToString() override;
	};

	public value struct SupplyView_FirstItem {
		String^ product_name;
		int product_id;

		String^ ToString() override;
	};

	public value struct CustomerView_FirstItem {
		String^ customer_lname;
		int customer_id;

		String^ ToString() override;
	};

	public value struct OrderView_FirstItem {
		String^ order_customer_str;
		int order_id;

		String^ ToString() override;
	};

	public value struct StaffView_FirstItem {
		String^ staff_lname;
		int staff_id;

		String^ ToString() override;
	};
};