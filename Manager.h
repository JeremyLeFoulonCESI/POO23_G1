#pragma once
#include "Table.h"
#include "DataBaseWrapper.h"

using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;

namespace Services {
	ref class Manager
	{
		DataBaseWrapper^ db;

	public:
		Manager();

	protected:
		array<Object^>^ dbCreateRow(Components::Table^ table, ...array<Object^>^ values);
		array<Object^>^ dbReadRow(Components::Table^ table, ...array<Object^>^ primary_keys);
		void dbUpdateRow(Components::Table^ table, array<Object^>^ values, ...array<Object^>^ primary_keys);
		void dbDeleteRow(Components::Table^ table, ...array<Object^>^ primary_keys);
		DataTable^ dbSearchRows(Components::Table^ table, array<String^>^ criteria_names, array<Object^>^ criteria_values);
		DataTable^ readAll(Components::Table^ table);
		void dbOpenConnection();
		void dbCloseConnection();
	};
}

