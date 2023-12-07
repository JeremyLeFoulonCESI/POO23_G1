#include "pch.h"
#include "StaffManager.h"

namespace Services {
    StaffManager::StaffManager():Manager(){}

    StaffMemberData StaffManager::addStaff(StaffMemberData data){
        array<Object^>^ array_data = gcnew array<Object^>{
            data.firstName,
            data.lastName,
            data.hireDate,
            data.superior,
            data.address
        };
        array<Object^>^ result_array = this->dbCreateRow(Components::Table::getStaffTable(), array_data);
        data.id = Convert::ToInt32(result_array[0]);
        return StaffMemberData();
    }

    StaffMemberData StaffManager::getStaff(int id){
        array<Object^>^ result_array = this->dbReadRow(Components::Table::getStaffTable(), id);
        StaffMemberData result = StaffMemberData();
        if (result_array->Length != 5)
            return result;
        result.id = id;
        result.firstName = safe_cast<String^>(result_array[0]);
        result.lastName = safe_cast<String^>(result_array[1]);
        result.hireDate = safe_cast<DateTime^>(result_array[2]);
        result.superior = *safe_cast<Int32^>(result_array[3]);
        //récupérer l'ID du membre du staff
        //récupérer l'ID de son adresse
        //récupérer l'ID de sa ville
        //result.address = {};
        return result;
    }

    StaffMemberData StaffManager::editStaff(int id, StaffMemberData _new){
        array<Object^>^ input_array = gcnew array<Object^> {
            _new.firstName,
                _new.lastName,
                _new.hireDate,
                _new.superior,
                _new.address
        };
        this->dbUpdateRow(Components::Table::getStaffTable(), input_array, id);
        _new.id = id;
        return _new;
    }

    void StaffManager::removeStaff(int id){
        this->dbDeleteRow(Components::Table::getStaffTable(), id);
    }

    DataTable^ StaffManager::getAllStaff(){ 
        DataTable^ raw_products = this->readAll(Components::Table::getStaffTable()); 
        DataTable^ result = gcnew DataTable;
        result->Columns->AddRange(gcnew array<DataColumn^>{
            gcnew DataColumn("Prenom"),
                gcnew DataColumn("Nom"),
                gcnew DataColumn("Date d'embauche"),
                gcnew DataColumn("ID du supérieur"),
                gcnew DataColumn("Adresse")
        });
        for each (DataRow ^ row in raw_products->Rows) { 
            result->Rows->Add(row->ItemArray); 
        }
        return result;
    }
}