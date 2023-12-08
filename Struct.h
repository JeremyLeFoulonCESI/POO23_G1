#pragma once

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace MySql::Data::Types;

namespace structure {
	value struct Column {
	public:
		String^ name;
		Object^ value;
	};

	value struct Address {
	public:
		String^ streetNum;
		String^ streetName;
		String^ cityName;
		String^ cityCode;
		String^ ToString() override;
	};

	value struct StaffMemberData {
	public:
		int id;
		String^ firstName;
		String^ lastName;
		DateTime^ hireDate;
		int superior;
		Address address;
	};

	value struct CustomerData {
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

	value struct ProductData {
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

	value struct OrderItem {
	public:
		ProductData product;
		int productCount;
		float discountRatio;
		float TaxRatio;
		float UHTPrice;
	};

	enum class PaymentMean {
		CreditCard,
		Cash
	};

	value struct Payment {
	public:
		PaymentMean mean;
		DateTime^ receptionDate;
		DateTime^ paymentDate;
		String^ ToString() override;
	};

	value struct OrderData {
	public:
		int id;
		String^ ref;
		DateTime^ deliveryDate;
		DateTime^ emissionDate;
		array<OrderItem>^ items;
		array<Payment>^ payments;
		CustomerData customer;
	};
};