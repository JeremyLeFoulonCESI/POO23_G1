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

	String^ structure::Address::ToString()
	{
		String^ ConcatanedString;
		ConcatanedString += streetNum;
		ConcatanedString += " ";
		ConcatanedString += streetName;
		ConcatanedString += " ";
		ConcatanedString += cityCode;
		ConcatanedString += " ";
		ConcatanedString += cityName;
		return ConcatanedString;
	}

	value struct StaffMemberData {
	public:
		int id;
		String^ firstName;
		String^ lastName;
		MySqlDateTime hireDate;
		int superior;
		Address address;
	};

	value struct CustomerData {
	public:
		int id;
		String^ firstName;
		String^ lastName;
		MySqlDateTime birth;
		String^ email;
		String^ phoneNumber;
		MySqlDateTime firstPurchase;
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

		String^ ToString() override {
			return "ProductData{ref=" + ref + ";nom=" + name + ";prix_UHT=" + priceNoTax + ";valeur_achat=" + purchaseValue +
				";qtté=" + amount + ";TVA=" + TVARatio + ";remise=" + discountRatio + ";seuil_reappro=" + restockThreshold + "}";
		}
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
		MySqlDateTime receptionDate;
		MySqlDateTime paymentDate;
		String^ ToString() override;
	};

	String^ Payment::ToString()
	{
		String^ mean_str;
		switch (mean) {
		case PaymentMean::Cash:
			mean_str = "Espèces";
			break;
		case PaymentMean::CreditCard:
			mean_str = "CB";
			break;
		default:
			mean_str = "<Inconnu>";
		}
		String^ ConcatanedString;
		ConcatanedString += mean_str;
		ConcatanedString += ", ";
		ConcatanedString += receptionDate;
		ConcatanedString += ", ";
		ConcatanedString += paymentDate;
		return ConcatanedString;
	}

	value struct OrderData {
	public:
		int id;
		String^ ref;
		MySqlDateTime deliveryDate;
		MySqlDateTime emissionDate;
		array<OrderItem>^ items;
		array<Payment>^ payments;
		CustomerData customer;
	};
};