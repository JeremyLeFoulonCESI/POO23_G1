#pragma once
#include <iostream>

namespace Components {

    using namespace System;
    using namespace MySql::Data::MySqlClient;

    ref class DataAccessor
    {
    public:
        static String^ insert(String^ table, String^ columns, ... array<Object^>^ values);

        static String^ update(String^ table, array<String^>^ columns, int ID, String^ primaryKey, ... array<Object^>^ values);

        static String^ select(String^ table, String^ criteria, ... array<String^>^ columns);

        static String^ remove(String^ table, String^ criteria);
    };

}


