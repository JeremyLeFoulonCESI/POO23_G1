#include "pch.h"
#include "Manager.h"
#include "Config.h"
#include "DataAccessor.h"
#include "DataBaseWrapper.h"


namespace Services {
	Manager::Manager() {
		this->db = gcnew DataBaseWrapper(
			gcnew String(Config::Server),
			gcnew String(Config::Database),
			gcnew String(Config::User),
			gcnew String(Config::Password)
		);
	}

	array<Object^>^ Manager::dbCreateRow(Components::Table^ table, ...array<Object^>^ values) {
		String^ query_str = Components::DataAccessor::insert(table->getName(), table->bundleForInsert(), values);
		Console::WriteLine(query_str);
		MySqlCommand^ query = this->db->basicQuery(query_str);
		query->ExecuteNonQuery();
		query->~MySqlCommand();
		return gcnew array<Object^>{ this->db->lastInsertedId() };
	}

	array<Object^>^ Manager::dbReadRow(Components::Table^ table, ...array<Object^>^ primary_keys) {
		String^ query_str = Components::DataAccessor::select(table->getName(), table->bindPrimaryKeysForUpdate(primary_keys), table->getKeys());
		MySqlCommand^ query = this->db->basicQuery(query_str);
		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(query);
		DataTable^ datatable = gcnew DataTable();
		adapter->Fill(datatable);
		query->~MySqlCommand();
		if (!datatable->Rows->Count) {
			return gcnew array<Object^>{};
		}
		return datatable->Rows[0]->ItemArray;
	}
	void Manager::dbUpdateRow(Components::Table^ table, array<Object^>^ values, ...array<Object^>^ primary_keys) {
		String^ query_str = Components::DataAccessor::update(table->getName(), table->bindKeysForUpdate(values), table->bindPrimaryKeysForUpdate(primary_keys));
		Console::WriteLine(query_str);
		MySqlCommand^ query = this->db->basicQuery(query_str);
		query->ExecuteNonQuery();
		query->~MySqlCommand();
	}
	void Manager::dbDeleteRow(Components::Table^ table, ...array<Object^>^ primary_keys) {
		String^ query_str = Components::DataAccessor::remove(table->getName(), table->bindPrimaryKeysForUpdate(primary_keys));
		Console::WriteLine(query_str);
		MySqlCommand^ query = this->db->basicQuery(query_str);
		query->ExecuteNonQuery();
		query->~MySqlCommand();
	}
	DataTable^ Manager::dbSearchRows(Components::Table^ table, array<String^>^ criteria_names, array<Object^>^ criteria_values)
	{
		String^ query_str = Components::DataAccessor::select(table->getName(), table->bindKeysForSearch(criteria_names, criteria_values), nullptr);
		return this->runRawQuery(query_str);
	}
	DataTable^ Manager::runRawQuery(String^ query_str)
	{
		MySqlCommand^ query = this->db->basicQuery(query_str);
		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(query);
		DataTable^ result = gcnew DataTable;
		adapter->Fill(result);
		query->~MySqlCommand();
		return result;
	}
	int Manager::dbCountRows(Components::Table^ table)
	{
		String^ query_str = Components::DataAccessor::count(table->getName());
		MySqlCommand^ query = this->db->basicQuery(query_str);
		int res = Convert::ToInt32(query->ExecuteScalar());
		query->~MySqlCommand();
		return res;
	}
	DataTable^ Manager::readAll(Components::Table^ table) {
		String^ query_str = Components::DataAccessor::select(table->getName(), "", nullptr);
		return this->runRawQuery(query_str);
	}
	void Manager::dbOpenConnection() {
		this->db->open();
	}
	void Manager::dbCloseConnection() {
		this->db->close();
	}
}

