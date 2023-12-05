#pragma once
#include <iostream>

using namespace System;
using namespace MySql::Data::MySqlClient; 

ref class DataAccessor
{
public:
    String^ insert(String^ table, String^ columns, ... array<Object^>^ values);

    String^ update(String^ table, array<String^>^ columns, int ID, String^ primaryKey, ... array<Object^>^ values);

    String^ select(String^ table, String^ criteria, ... array<String^>^ columns);

    String^ remove(String^ table, String^ criteria);
};


