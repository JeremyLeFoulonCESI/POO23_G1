#include "pch.h"
#include "Table.h"


namespace Components {
	Table::Table(String^ name, array<String^>^ primary_keys, array<String^>^ keys) :
		name(name), primary_keys(primary_keys), keys(keys)
	{}

	String^ Table::bindKeysForUpdate(... array<Object^>^ values) {
		String^ result = "";

		if (values->Length < this->keys->Length) {
			return result;
		}
		result += "(";

		for (int i = 0; i < this->keys->Length; i++) {
			String^ key = this->keys[i];
			Object^ value = values[i];
			result += key + " = " + value + ",";
		}

		if (keys->Length > 0 && result->EndsWith(",")) {
			result = result->Remove(result->Length - 2);
		}

		result += ")";
		return result;
	}

	String^ Table::bindPrimaryKeysForUpdate(... array<Object^>^ values) {
		String^ result = "";

		if (values->Length < this->primary_keys->Length) {
			return result;
		}
		result += "(";

		for (int i = 0; i < this->primary_keys->Length; i++) {
			String^ key = this->primary_keys[i];
			Object^ value = values[i];
			result += key + " = " + value + ",";
		}

		if (result->Length > 0 && result->EndsWith(",")) {
			result = result->Remove(result->Length - 2);
		}

		result += ")";
		return result;
	}
	String^ Table::bundleForInsert() {
		String^ result = "(";
		for each (String ^ key in this->keys) {
			result += key + ",";
		}
		if (result->Length > 0 && result->EndsWith(",")) {
			result = result->Remove(result->Length - 2);
		}
		result += ")";
		return result;
	}
	array<String^>^ Table::getPrimaryKeys() {
		return this->primary_keys;
	}
	array<String^>^ Table::getKeys() {
		return this->keys;
	}
	String^ Table::getName() {
		return this->name;
	}
}

