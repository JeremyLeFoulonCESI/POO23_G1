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

	CustomerData CustomerManager::getCustomer(int id) {

		DataTable^ found = this->dbSearchRows(Components::Table::getAddressTable(),
			gcnew array<String^> {"CodeClient_ClientLivre"},
			gcnew array<Object^> {Int32(id)}
		);

		List<Address>^ delivery_addresses = gcnew List<Address>();
		for each (DataRow^ row in found->Rows) {

			int id_city = Convert::ToInt32(row->ItemArray[3]);

			array<Object^>^ array_city = this->dbReadRow(Components::Table::getCityTable(), id_city);
			
			Address address = Address();
			address.streetNum = Convert::ToString(row->ItemArray[1]);
			address.streetName = Convert::ToString(row->ItemArray[2]);
			address.cityName = Convert::ToString(array_city[1]);
			address.cityCode = Convert::ToString(array_city[2]);

			delivery_addresses->Add(address);
		}

		found = this->dbSearchRows(Components::Table::getAddressTable(),
			gcnew array<String^> {"CodeClient_ClientFacture"},
			gcnew array<Object^> {Int32(id)}
		);

		List<Address>^ invoice_addresses = gcnew List<Address>();
		for each (DataRow ^ row in found->Rows) {

			int id_city = Convert::ToInt32(row->ItemArray[3]);

			array<Object^>^ array_city = this->dbReadRow(Components::Table::getCityTable(), id_city);

			Address address = Address();
			address.streetNum = Convert::ToString(row->ItemArray[1]);
			address.streetName = Convert::ToString(row->ItemArray[2]);
			address.cityName = Convert::ToString(array_city[1]);
			address.cityCode = Convert::ToString(array_city[2]);

			invoice_addresses->Add(address);
		}

		array<Object^>^ array_customer = this->dbReadRow(Components::Table::getCustomerTable(), id);

		CustomerData result = CustomerData();
		result.id = id;
		result.lastName = Convert::ToString(array_customer[1]);
		result.firstName = Convert::ToString(array_customer[2]);
		result.birth = safe_cast<MySqlDateTime>(array_customer[3]);
		result.email = Convert::ToString(array_customer[4]);
		result.phoneNumber = Convert::ToString(array_customer[5]);
		result.firstPurchase = safe_cast<MySqlDateTime>(array_customer[6]);
		result.deliveryAddresses = delivery_addresses->ToArray();
		result.invoiceAdresses = invoice_addresses->ToArray();
		return result;
	}
}
