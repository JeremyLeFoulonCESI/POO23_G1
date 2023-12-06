#pragma once
#include <iostream>

using namespace System;
using namespace MySql::Data::MySqlClient;


namespace Components {


    ref class DataAccessor
    {
    public:
        static String^ insert(String^ table, String^ keys, ... array<Object^>^ values);

        static String^ update(String^ table, String^ bound_keys, String^ bound_primary_keys);

        static String^ select(String^ table, String^ criteria, ... array<String^>^ keys);

        static String^ remove(String^ table, String^ criteria);
    };

}


