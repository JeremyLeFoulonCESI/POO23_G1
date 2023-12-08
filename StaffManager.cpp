#include "pch.h"
#include "StaffManager.h"

namespace Services {
    StaffManager::StaffManager() : Manager() {}

    StaffMemberData StaffManager::addStaff(StaffMemberData data){
        this->dbOpenConnection();

        DataTable^ found_address = this->dbSearchRows(
            Components::Table::getCityTable(),
            gcnew array<String^>{ "NomVille", "CodePostal" },
            gcnew array<Object^>{ data.address.cityName, data.address.cityCode }
        );
        int city_id = Convert::ToInt32(found_address->Rows[0]->ItemArray[0]);

        array<Object^>^ address_array = gcnew array<Object^>{
            data.address.streetNum, data.address.streetName, city_id, "NULL", "NULL"
        };

        array<Object^>^ address_created_array = this->dbCreateRow(Components::Table::getAddressTable(), address_array);
        int address_id = Convert::ToInt32(address_created_array[0]);

        array<Object^>^ staff_array = gcnew array<Object^>{
            data.lastName, data.firstName, data.hireDate, address_id, data.superior
        };
        array<Object^>^ created_staff = this->dbCreateRow(Components::Table::getStaffTable(), staff_array);
        this->dbCloseConnection();
        data.id = Convert::ToInt32(created_staff[0]);
        return data;
    }

    StaffMemberData StaffManager::getStaff(int id){
        StaffMemberData result = StaffMemberData();

        this->dbOpenConnection();
        array<Object^>^ staff_array = this->dbReadRow(Components::Table::getStaffTable(), id);
        result.id = id;
        result.lastName = Convert::ToString(staff_array[0]);
        result.firstName = Convert::ToString(staff_array[1]);
        result.hireDate = safe_cast<DateTime^>(staff_array[2]);
        result.superior = Convert::ToInt32(staff_array[4]);

        int address_id = Convert::ToInt32(staff_array[3]);
        array<Object^>^ address_array = this->dbReadRow(Components::Table::getAddressTable(), address_id);
        result.address.streetNum = Convert::ToString(address_array[0]);
        result.address.streetName = Convert::ToString(address_array[1]);

        int city_id = Convert::ToInt32(address_array[2]);
        array<Object^>^ city_array = this->dbReadRow(Components::Table::getCityTable(), city_id);
        this->dbCloseConnection();
        result.address.cityName = Convert::ToString(city_array[0]);
        result.address.cityCode = Convert::ToString(city_array[1]);

        return result;
    }

    StaffMemberData StaffManager::editStaff(int id, StaffMemberData _new){
        
        this->dbOpenConnection();
        array<Object^>^ staff_data = this->dbReadRow(Components::Table::getStaffTable(), id);
        int prev_address_id = Convert::ToInt32(staff_data[3]);

        DataTable^ city_table = this->dbSearchRows(
            Components::Table::getCityTable(),
            gcnew array<String^>{ "NomVille", "CodePostal" },
            gcnew array<Object^>{ _new.address.cityName, _new.address.cityCode }
        );
        int city_id = Convert::ToInt32(city_table->Rows[0]->ItemArray[0]);

        array<Object^>^ address_array = gcnew array<Object^>{
            _new.address.streetNum, _new.address.streetName, city_id, "NULL", "NULL"
        };
        array<Object^>^ address_data = this->dbCreateRow(Components::Table::getAddressTable(), address_array);
        int address_id = Convert::ToInt32(address_data[0]);

        array<Object^>^ staff_array = gcnew array<Object^>{
            _new.lastName, _new.firstName, _new.hireDate, address_id, _new.superior
        };
        this->dbUpdateRow(Components::Table::getStaffTable(), staff_array, id);

        this->dbDeleteRow(Components::Table::getAddressTable(), prev_address_id);
        this->dbCloseConnection();

        _new.id = id;
        return _new;
    }

    void StaffManager::removeStaff(int id){

        this->dbOpenConnection();
        array<Object^>^ staff_data = this->dbReadRow(Components::Table::getStaffTable(), id);
        int address_id = Convert::ToInt32(staff_data[3]);

        this->dbDeleteRow(Components::Table::getStaffTable(), id);
        this->dbDeleteRow(Components::Table::getAddressTable(), address_id);
        this->dbCloseConnection();
    }

    int StaffManager::count() {
        this->dbOpenConnection();
        int result = this->dbCountRows(Components::Table::getStaffTable());
        this->dbCloseConnection();
        return result;
    }

    DataTable^ StaffManager::getAllStaff(){ 
        DataTable^ result = gcnew DataTable();

        result->Columns->AddRange(gcnew array<DataColumn^>{
            gcnew DataColumn("Nom"),
            gcnew DataColumn("Prénom"),
            gcnew DataColumn("Date d'embauche"),
            gcnew DataColumn("Adresse"),
            gcnew DataColumn("Supérieur hiérarchique")
        });

        this->dbOpenConnection();
        DataTable^ found_staff = this->readAll(Components::Table::getStaffTable());


        for each (DataRow^ staff_row in found_staff->Rows) {
            
            int address_id = Convert::ToInt32(staff_row->ItemArray[4]);
            array<Object^>^ address_data = this->dbReadRow(Components::Table::getAddressTable(), address_id);
            
            int city_id = Convert::ToInt32(address_data[2]);
            array<Object^>^ city_data = this->dbReadRow(Components::Table::getCityTable(), city_id);

            Address address = Address();
            address.cityName = Convert::ToString(city_data[0]);
            address.cityCode = Convert::ToString(city_data[1]);
            address.streetNum = Convert::ToString(address_data[0]);
            address.streetName = Convert::ToString(address_data[1]);

            String^ address_str = address.ToString();

            int superior_id = Convert::ToInt32(staff_row->ItemArray[5]);
            array<Object^>^ superior_data = this->dbReadRow(Components::Table::getStaffTable(), superior_id);
            String^ superior_lname = Convert::ToString(superior_data[0]);
            String^ superior_fname = Convert::ToString(superior_data[1]);
            String^ superior_str = superior_lname + " " + superior_fname;

            DateTime^ hire_date = safe_cast<DateTime^>(staff_row->ItemArray[3]);
            String^ hire_date_str = hire_date->Day + "." + hire_date->Month + "." + hire_date->Year;

            String^ lname = Convert::ToString(staff_row->ItemArray[1]);
            String^ fname = Convert::ToString(staff_row->ItemArray[2]);

            result->Rows->Add(lname, fname, hire_date_str, address_str, superior_str);
        }
        this->dbCloseConnection();
        return result;
    }
}