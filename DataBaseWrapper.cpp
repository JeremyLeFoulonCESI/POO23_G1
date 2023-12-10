#include "pch.h"
#include "DataBaseWrapper.h"

DataBaseWrapper::DataBaseWrapper(String^ server, String^ database, String^ username, String^ password)
{
    this->connect_string = "server = " + server + "; uid = " + username + "; pwd = " + password + "; database = " + database;
}

void DataBaseWrapper::open()
{
    this->connection = gcnew MySqlConnection;
    this->connection->ConnectionString = connect_string;
    connection->Open();
}

MySqlCommand^ DataBaseWrapper::basicQuery(String^ query, ...array<Object^>^ parameters)
{
    MySqlCommand^ command = this->connection->CreateCommand();
    Console::WriteLine(query);
    command->CommandText = query;
    command->Prepare();
    return command;
}

Object^ DataBaseWrapper::lastInsertedId()
{
    MySqlCommand^ command = this->basicQuery("SELECT LAST_INSERT_ID();");
    Object^ result = command->ExecuteScalar();
    command->~MySqlCommand();
    return result;
}

void DataBaseWrapper::close()
{
    if (this->connection != nullptr) {
        this->connection->Close();
        this->connection = nullptr;
    }
}

