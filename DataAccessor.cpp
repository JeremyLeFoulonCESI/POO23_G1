#include "pch.h"
#include "DataAccessor.h"
#include "SqlData.h"


namespace Components {


    String^ DataAccessor::insert(String^ table, String^ columns, ... array<Object^>^ values)
    {
        String^ query = "INSERT INTO " + table + " " + columns + " VALUES (";
        for each (Object^ obj in values) {
            query += SqlData::ObjectToSql(obj) + ", ";
        };

        if (query->EndsWith(", ")) {
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
            //query += "(";
            for each (String ^ name in keys) {
                query += "`" + name + "`, ";
            };

            if (query->EndsWith(", ")) {
                query = query->Remove(query->Length - 2);
            }
            query += " ";
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

    String^ DataAccessor::count(String^ table)
    {
        String^ query = "SELECT count(*) FROM " + table + ";";
        return query;
    }

    String^ DataAccessor::best_sellers()
    {
        return "select Nom, Reference, sum(NbArticles) as total \
            from articles left join contient \
            on contient.Reference_Article = articles.Reference \
            group by Reference \
            order by total desc \
            limit 10; ";
    }

    String^ DataAccessor::worst_sellers() {
        return "select Nom, Reference, sum(NbArticles) as total \
            from articles left join contient \
            on contient.Reference_Article = articles.Reference \
            group by Reference \
            order by total \
            limit 10; ";
    }
    
}

