#pragma once

using namespace System;
using namespace MySql::Data::MySqlClient;

public ref class DataBaseWrapper
{
private:
	String^ connect_string;
	MySqlConnection^ connection;

public:
	DataBaseWrapper(String^ server, String^ database, String^ username, String^ password);
	void open();
	MySqlCommand^ basicQuery(String^ query, ... array<Object^>^ parameters);
	Object^ lastInsertedId();
	void close();
};

