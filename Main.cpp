#include "pch.h"
#include "Root.h"

#include "DataAccessor.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;

void test_DataAccessor() {

    String^ insert = Components::DataAccessor::insert("Client", "(col_a, col_b, col_c)", 1, 2, 3);
    Console::WriteLine(insert);
    // attendu: INSERT INTO Client (col_a, col_b, col_c) VALUES (1, 2, 3)

    String^ update = Components::DataAccessor::update("Client", "col_a = 1, col_b = 2, col_b = 3", "col_a = 1");
    Console::WriteLine(update);
    // attendu: UPDATE Client SET col_a = 4, col_b = 5, col_c = 6 WHERE id = 1

    String^ select = Components::DataAccessor::select("Client", "col_a = 2, col_b = 3", "col_a", "col_b", "col_c");
    Console::WriteLine(select);
    // attendu: SELECT (col_a, col_b, col_c) FROM Client WHERE col_a = 2, col_b = 3

    String^ remove = Components::DataAccessor::remove("Client", "col_c = 6");
    Console::WriteLine(remove);
    // attendu: DELETE FROM Client WHERE col_c = 6
}


int main(array<System::String ^> ^args)
{
    //Application::CurrentCulture = gcnew System::Globalization::CultureInfo("en-US");
    HMI::Root^ root = gcnew HMI::Root();
    Application::Run(root);
}
