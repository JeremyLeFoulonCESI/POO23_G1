#include "pch.h"
#include "DataAccessor.h"


namespace Components {


    String^ DataAccessor::insert(String^ table, String^ columns, ... array<Object^>^ values)
    {
        String^ query = "INSERT INTO " + table + " (" + columns + ") VALUES (";
        for each (Object ^ obj in values) {
            String^ suiteQuery = obj->ToString();
            query += "'" + suiteQuery + "', ";
        };

        if (values->Length > 0) {
            query = query->Remove(query->Length - 2);
        };

        query += ");";
        return query;
    }

    String^ DataAccessor::update(String^ table, String^ bound_keys, String^ bound_primary_keys)
    {
        String^ query = "UPDATE " + table + " SET " + bound_keys;

        if (bound_primary_keys->Length > 1)
            query += " WHERE " + bound_primary_keys + ";";
        return query;
    }

    String^ DataAccessor::select(String^ table, String^ criteria, ... array<String^>^ keys)
    {
        String^ query = "SELECT ";
        if (keys == nullptr || !keys->Length) {
            query += "* ";
        }
        else {
            query += "(";
            for each (String ^ name in keys) {
                query += name + ", ";
            };

            if (keys->Length > 0) {
                query = query->Remove(query->Length - 2);
            }
            query += ") ";
        }

        query += "FROM " + table;
        if (criteria->Length)
            query += " WHERE " + criteria;
        query += ";";
        return query;
    }

    String^ DataAccessor::remove(String^ table, String^ criteria)
    {
        String^ query = "DELETE FROM ";
        query += table + " WHERE " + criteria + ";";
        return query;
    }
    
}

