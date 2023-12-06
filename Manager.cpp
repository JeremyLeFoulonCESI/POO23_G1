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
		MySqlCommand^ query = this->db->basicQuery(query_str);
		query->ExecuteNonQuery();
		return gcnew array<Object^>{ this->db->lastInsertedId() };
	}

	array<Object^>^ Manager::dbReadRow(Components::Table^ table, ...array<Object^>^ primary_keys) {
		String^ query_str = Components::DataAccessor::select(table->getName(), table->bindPrimaryKeysForUpdate(primary_keys), table->getKeys());
		MySqlCommand^ query = this->db->basicQuery(query_str);
		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(query);
		DataTable^ datatable = gcnew DataTable();
		adapter->Fill(datatable);
		if (!datatable->Rows->Count) {
			return gcnew array<Object^>{};
		}
		return datatable->Rows[0]->ItemArray;
	}
	void Manager::dbUpdateRow(Components::Table^ table, array<Object^>^ values, ...array<Object^>^ primary_keys) {
		String^ query_str = Components::DataAccessor::update(table->getName(), table->bindKeysForUpdate(values), table->bindPrimaryKeysForUpdate(primary_keys));
		MySqlCommand^ query = this->db->basicQuery(query_str);
		query->ExecuteNonQuery();
	}
	void Manager::dbDeleteRow(Components::Table^ table, ...array<Object^>^ primary_keys) {
		String^ query_str = Components::DataAccessor::remove(table->getName(), table->bindPrimaryKeysForUpdate(primary_keys));
		MySqlCommand^ query = this->db->basicQuery(query_str);
		query->ExecuteNonQuery();
	}
	DataTable^ Manager::readAll(Components::Table^ table) {
		String^ query_str = Components::DataAccessor::select(table->getName(), "", nullptr);
		MySqlCommand^ query = this->db->basicQuery(query_str);
		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(query);
		DataTable^ result = gcnew DataTable;
		adapter->Fill(result);
		return result;
	}
	void Manager::dbOpenConnection() {
		this->db->open();
	}
	void Manager::dbCloseConnection() {
		this->db->close();
	}
}

