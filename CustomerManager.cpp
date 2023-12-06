#include "pch.h"
#include "CustomerManager.h"


namespace Services {
	CustomerManager::CustomerManager() :
		Manager()
	{}

	CustomerData CustomerManager::addCustomer(CustomerData data) {
		array<Object^>^ customer_array = gcnew array<Object^> {
			data.lastName,
			data.firstName,
			data.birth,
			data.email,
			data.phoneNumber,
			data.firstPurchase
		};

		array<Object^>^ primary = this->dbCreateRow(Components::Table::getCustomerTable(), customer_array);
		int id_customer = Convert::ToInt32(primary[0]);

		for each (Address address in data.deliveryAddresses) {
			array<Object^>^ city_array = gcnew array<Object^> {
				address.cityName,
				address.cityCode,
			};
			DataTable^ found = this->dbSearchRows(Components::Table::getAddressTable(), gcnew array<String^>{"NomVille", "CodePostal"}, city_array);
			DataRow^ city_row = found->Rows[0];
			int id_city = Convert::ToInt32(city_row->ItemArray[0]);

			array<Object^>^ address_array = gcnew array<Object^> {
				address.streetNum, address.streetName, id_city, id_customer, gcnew String("NULL")
			};
			this->dbCreateRow(Components::Table::getAddressTable(), address_array);
		}

		for each (Address address in data.invoiceAdresses) {
			array<Object^>^ city_array = gcnew array<Object^> {
				address.cityName,
					address.cityCode,
			};
			DataTable^ found = this->dbSearchRows(Components::Table::getAddressTable(), gcnew array<String^>{"NomVille", "CodePostal"}, city_array);
			DataRow^ city_row = found->Rows[0];
			int id_city = Convert::ToInt32(city_row->ItemArray[0]);

			array<Object^>^ address_array = gcnew array<Object^> {
				address.streetNum, address.streetName, id_city, gcnew String("NULL"), id_customer
			};
			this->dbCreateRow(Components::Table::getAddressTable(), address_array);
		}

		data.id = id_customer;
		return data;
	}
}
