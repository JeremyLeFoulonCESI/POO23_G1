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
		this->dbOpenConnection();

		array<Object^>^ primary = this->dbCreateRow(Components::Table::getCustomerTable(), customer_array);
		int id_customer = Convert::ToInt32(primary[0]);

		for each (Address address in data.deliveryAddresses) {
			array<Object^>^ city_array = gcnew array<Object^> {
				address.cityName,
				address.cityCode,
			};
			DataTable^ city_found = this->dbSearchRows(Components::Table::getCityTable(), gcnew array<String^>{"NomVille", "CodePostal"}, city_array);
			DataRow^ city_row = city_found->Rows[0];
			int id_city = Convert::ToInt32(city_row->ItemArray[0]);

			array<Object^>^ address_array = gcnew array<Object^> {
				address.streetNum, 
				address.streetName, 
				id_city, 
				id_customer, 
				nullptr
			};
			this->dbCreateRow(Components::Table::getAddressTable(), address_array);
		}

		for each (Address address in data.invoiceAdresses) {
			array<Object^>^ city_array = gcnew array<Object^> {
				address.cityName,
					address.cityCode,
			};
			DataTable^ found_city = this->dbSearchRows(Components::Table::getCityTable(), gcnew array<String^>{"NomVille", "CodePostal"}, city_array);
			DataRow^ city_row = found_city->Rows[0];
			int id_city = Convert::ToInt32(city_row->ItemArray[0]);

			array<Object^>^ address_array = gcnew array<Object^> {
				address.streetNum, address.streetName, id_city, nullptr, id_customer
			};
			this->dbCreateRow(Components::Table::getAddressTable(), address_array);
		}

		this->dbCloseConnection();
		data.id = id_customer;
		return data;
	}

	CustomerData CustomerManager::getCustomer(int id) {
		this->dbOpenConnection();
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
			address.cityName = Convert::ToString(array_city[0]);
			address.cityCode = Convert::ToString(array_city[1]);

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
			address.cityName = Convert::ToString(array_city[0]);
			address.cityCode = Convert::ToString(array_city[1]);

			invoice_addresses->Add(address);
		}

		array<Object^>^ array_customer = this->dbReadRow(Components::Table::getCustomerTable(), id);
		this->dbCloseConnection();

		CustomerData result = CustomerData();
		result.id = id;
		result.lastName = Convert::ToString(array_customer[0]);
		result.firstName = Convert::ToString(array_customer[1]);
		result.birth = safe_cast<DateTime^>(array_customer[2]);
		result.email = Convert::ToString(array_customer[3]);
		result.phoneNumber = Convert::ToString(array_customer[4]);
		result.firstPurchase = safe_cast<DateTime^>(array_customer[5]);
		result.deliveryAddresses = delivery_addresses->ToArray();
		result.invoiceAdresses = invoice_addresses->ToArray();
		return result;
	}
	CustomerData CustomerManager::editCustomer(int id, CustomerData _new) {

		array<Object^>^ customer_array = gcnew array<Object^> {
			_new.lastName,
			_new.firstName,
			_new.birth,
			_new.email,
			_new.phoneNumber,
			_new.firstPurchase
		};

		this->dbOpenConnection();
		this->dbUpdateRow(Components::Table::getCustomerTable(), customer_array, id);


		DataTable^ previous_delivery_addresses = this->dbSearchRows(Components::Table::getAddressTable(), 
			gcnew array<String^>{ "CodeClient_ClientLivre" }, 
			gcnew array<Object^>{ id }
		);
		DataTable^ previous_invoice_addresses = this->dbSearchRows(Components::Table::getAddressTable(),
			gcnew array<String^>{ "CodeClient_ClientFacture" },
			gcnew array<Object^>{ id }
		);


		for each (Address address in _new.deliveryAddresses) {
			array<Object^>^ city_array = gcnew array<Object^> {
				address.cityName,
				address.cityCode
			};
			DataTable^ found = this->dbSearchRows(Components::Table::getCityTable(), gcnew array<String^>{"NomVille", "CodePostal"}, city_array);
			DataRow^ city_row = found->Rows[0];
			int id_city = Convert::ToInt32(city_row->ItemArray[0]);

			array<Object^>^ address_array = gcnew array<Object^> {
				address.streetNum,
				address.streetName,
				id_city,
				id,
				nullptr
			};
			this->dbCreateRow(Components::Table::getAddressTable(), address_array);
		}

		for each (DataRow^ row in previous_delivery_addresses->Rows) {
			int id_address = Convert::ToInt32(row->ItemArray[0]);
			this->dbDeleteRow(Components::Table::getAddressTable(), id_address);
		}

		for each (Address address in _new.invoiceAdresses) {
			array<Object^>^ city_array = gcnew array<Object^> {
				address.cityName,
				address.cityCode,
			};
			DataTable^ found = this->dbSearchRows(Components::Table::getCityTable(), gcnew array<String^>{"NomVille", "CodePostal"}, city_array);
			DataRow^ city_row = found->Rows[0];
			int id_city = Convert::ToInt32(city_row->ItemArray[0]);

			array<Object^>^ address_array = gcnew array<Object^> {
				address.streetNum, address.streetName, id_city, nullptr, id
			};
			this->dbCreateRow(Components::Table::getAddressTable(), address_array);
		}
		for each (DataRow ^ row in previous_invoice_addresses->Rows) {
			int id_address = Convert::ToInt32(row->ItemArray[0]);
			this->dbDeleteRow(Components::Table::getAddressTable(), id_address);
		}
		this->dbCloseConnection();
		_new.id = id;
		return _new;
	}
	void CustomerManager::removeCustomer(int id) {
		this->dbOpenConnection();
		DataTable^ delivery_addresses = this->dbSearchRows(Components::Table::getAddressTable(),
			gcnew array<String^>{ "CodeClient_ClientLivre" },
			gcnew array<Object^>{ id }
		);
		DataTable^ invoice_addresses = this->dbSearchRows(Components::Table::getAddressTable(),
			gcnew array<String^>{ "CodeClient_ClientFacture" },
			gcnew array<Object^>{ id }
		);
		for each (DataRow ^ row in delivery_addresses->Rows) {
			int id_address = Convert::ToInt32(row->ItemArray[0]);
			this->dbDeleteRow(Components::Table::getAddressTable(), id_address);
		}
		for each (DataRow ^ row in invoice_addresses->Rows) {
			int id_address = Convert::ToInt32(row->ItemArray[0]);
			this->dbDeleteRow(Components::Table::getAddressTable(), id_address);
		}
		this->dbDeleteRow(Components::Table::getCustomerTable(), id);
		this->dbCloseConnection();
	}
	int CustomerManager::count() {
		this->dbOpenConnection();
		int result = this->dbCountRows(Components::Table::getCustomerTable());
		this->dbCloseConnection();
		return result;
	}
	DataTable^ CustomerManager::getAllCustomers() {
		DataTable^ result = gcnew DataTable;
		result->Columns->AddRange(gcnew array<DataColumn^>{
			gcnew DataColumn("Nom", Object::typeid),
			gcnew DataColumn("Prénom"),
			gcnew DataColumn("Date de naissance"),
			gcnew DataColumn("Adresse email"),
			gcnew DataColumn("Numéro de téléphone"),
			gcnew DataColumn("Date de premier achat"),
			gcnew DataColumn("Adresses de livraison"),
			gcnew DataColumn("Adresses de facturation"),
			gcnew DataColumn("ID")
		});

		this->dbOpenConnection();
		DataTable^ found = this->readAll(Components::Table::getCustomerTable());

		for each (DataRow ^ customer_row in found->Rows) {
			int id_customer = Convert::ToInt32(customer_row->ItemArray[0]);

			DataTable^ found_delivery = this->dbSearchRows(Components::Table::getAddressTable(),
				gcnew array<String^> { "CodeClient_ClientLivre" },
				gcnew array<Object^> { id_customer }
			);

			String^ delivery_addresses_str = "";
			for each (DataRow ^ row in found_delivery->Rows) {

				int id_city = Convert::ToInt32(row->ItemArray[3]);

				array<Object^>^ array_city = this->dbReadRow(Components::Table::getCityTable(), id_city);

				Address address = Address();
				address.streetNum = Convert::ToString(row->ItemArray[1]);
				address.streetName = Convert::ToString(row->ItemArray[2]);
				address.cityName = Convert::ToString(array_city[0]);
				address.cityCode = Convert::ToString(array_city[1]);

				delivery_addresses_str += address.ToString();
				delivery_addresses_str += ";";
			}
			if (delivery_addresses_str->EndsWith(";")) {
				delivery_addresses_str = delivery_addresses_str->Remove(delivery_addresses_str->Length - 1, 1);
			}

			DataTable^ found_invoice = this->dbSearchRows(Components::Table::getAddressTable(),
				gcnew array<String^> { "CodeClient_ClientFacture" },
				gcnew array<Object^> { id_customer }
			);

			String^ invoice_addresses_str = "";
			for each (DataRow ^ row in found_invoice->Rows) {

				int id_city = Convert::ToInt32(row->ItemArray[3]);

				array<Object^>^ array_city = this->dbReadRow(Components::Table::getCityTable(), id_city);

				Address address = Address();
				address.streetNum = Convert::ToString(row->ItemArray[1]);
				address.streetName = Convert::ToString(row->ItemArray[2]);
				address.cityName = Convert::ToString(array_city[0]);
				address.cityCode = Convert::ToString(array_city[1]);

				invoice_addresses_str += address.ToString();
				invoice_addresses_str += ";";
			}
			if (invoice_addresses_str->EndsWith(";")) {
				invoice_addresses_str = invoice_addresses_str->Remove(invoice_addresses_str->Length - 1);
			}

			CustomerView_FirstItem^ first = gcnew CustomerView_FirstItem();
			first->customer_lname = Convert::ToString(customer_row[1]);
			first->customer_id = Convert::ToInt32(customer_row[0]);
			
			result->Rows->Add(
				first,
				customer_row[2],
				customer_row[3],
				customer_row[4],
				customer_row[5],
				customer_row[6],
				delivery_addresses_str,
				invoice_addresses_str,
				id_customer
			);
		}
		this->dbCloseConnection();
		return result;
	}
}
