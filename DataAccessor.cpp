#include "pch.h"
#include "DataAccessor.h"


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

String^ DataAccessor::update(String^ table, array<String^>^ columns, int ID, String^ primaryKey, ... array<Object^>^ values)
{
    String^ query = "UPDATE " + table + " SET ";
    for (int i = 0; i < columns->Length; i++) {
        String^ name = columns[i];
        Object^ value = values[i];
        query += name + " = ";
        query += "'" + value + "', ";
    };

    if (values->Length > 0) {
        query = query->Remove(query->Length - 2);
    };

    query += " WHERE " + primaryKey + " = " + ID + ";";
    return query;
}

String^ DataAccessor::select(String^ table, String^ criteria, ... array<String^>^ columns)
{
    String^ query = "SELECT (";
    for each (String ^ name in columns) {
        query += name + ", ";
    };

    if (columns->Length > 0) {
        query = query->Remove(query->Length - 2);
    };

    query += ") ";
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

