#pragma once

using namespace System;


namespace Components {

	ref class Table
	{
		String^ name;
		array<String^>^ primary_keys;
		array<String^>^ keys;

	public:
		Table(String^ name, array<String^>^ primary_keys, array<String^>^ keys);
		String^ bindKeysForUpdate(...array<Object^>^ values);
		String^ bindPrimaryKeysForUpdate(...array<Object^>^ values);
		String^ bundleForInsert();
		array<String^>^ getPrimaryKeys();
		array<String^>^ getKeys();
		String^ getName();

		static Table^ getStaffTable();
		static Table^ getCityTable();
		static Table^ getAddressTable();
		static Table^ getCustomerTable();
		static Table^ getOrderTable();
		static Table^ getContainsTable();
		static Table^ getProductTable();
		static Table^ getPaymentTable();
	};
}

