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

	String^ Table::bindKeysForSearch(array<String^>^ key_names, array<Object^>^ key_values) {
		String^ result = "";
		
		if (key_names->Length != key_values->Length) {
			return result;
		}

		for (int i = 0; i < key_names->Length; i++) {
			String^ key_name = key_names[i];
			Object^ key_value = key_values[i];

			result += key_name + " = " + key_value + ",";
		}
		if (result->Length > 0 && result->EndsWith(",")) {
			result = result->Remove(result->Length - 2);
		}
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

	Table^ Table::getStaffTable()
	{
		String^ name = "Personnel";
		array<String^>^ primaryKeys = gcnew array<String^> { "ID" };
		array<String^>^ keys = gcnew array<String^> { "Nom", "Prenom", "DateEmbauche", "ID_Adresse", "ID_Superieur" };

		return gcnew Table(name, primaryKeys, keys);
	}

	Table^ Table::getCityTable()
	{
		String^ name = "Ville";
		array<String^>^ primaryKeys = gcnew array<String^> { "ID" };
		array<String^>^ keys = gcnew array<String^> { "NomVille", "CodePostal" };

		return gcnew Table(name, primaryKeys, keys);
	}

	Table^ Table::getAddressTable()
	{
		String^ name = "Adresse";
		array<String^>^ primaryKeys = gcnew array<String^> { "ID" };
		array<String^>^ keys = gcnew array<String^> { "NumRue", "Rue", "ID_Ville", "CodeClient_ClientLivre", "CodeClient_ClientFacture" };

		return gcnew Table(name, primaryKeys, keys);
	}

	Table^ Table::getCustomerTable()
	{
		String^ name = "Clients";
		array<String^>^ primaryKeys = gcnew array<String^> { "CodeClient" };
		array<String^>^ keys = gcnew array<String^> { "Nom", "Prenom", "DateNaissance", "AdresseMail", "NumTel", "DatePremierAchat" };

		return gcnew Table(name, primaryKeys, keys);
	}

	Table^ Table::getOrderTable()
	{
		String^ name = "Commande";
		array<String^>^ primaryKeys = gcnew array<String^> { "ID" };
		array<String^>^ keys = gcnew array<String^> { "Reference", "DateLivraison", "DateEmission", "CodeClient" };

		return gcnew Table(name, primaryKeys, keys);
	}

	Table^ Table::getContainsTable()
	{
		String^ name = "Contient";
		array<String^>^ primaryKeys = gcnew array<String^> { "ID_Commande", "Reference_Article" };
		array<String^>^ keys = gcnew array<String^> { "NbArticles", "TauxRemises", "TauxTVA", "PrixUHT" };

		return gcnew Table(name, primaryKeys, keys);
	}

	Table^ Table::getProductTable()
	{
		String^ name = "Articles";
		array<String^>^ primaryKeys = gcnew array<String^> { "Reference" };
		array<String^>^ keys = gcnew array<String^> { "Nom", "PrixUHT", "PrixUA", "Quantité", "TauxTVA", "TauxRemises", "SeuilReapro" };

		return gcnew Table(name, primaryKeys, keys);
	}

	Table^ Table::getPaymentTable()
	{
		String^ name = "Paiement";
		array<String^>^ primaryKeys = gcnew array<String^> { "ID" };
		array<String^>^ keys = gcnew array<String^> { "MoyenPaiement", "DateEncaissement", "DatePaiement", "ID_Commande" };

		return gcnew Table(name, primaryKeys, keys);
	}
}

