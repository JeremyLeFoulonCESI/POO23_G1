#include "pch.h"
#include "SqlData.h"

namespace Components {

    String^ SqlData::ObjectToSql(Object^ src)
    {
        /*if (src != nullptr)
            Console::WriteLine("Type: " + src->GetType()->Name);
        else
            Console::WriteLine("Type: <null>");*/
        if (src == nullptr) {
            return "NULL";
        }
        if (src->GetType()->IsSubclassOf(String::typeid) || (src->GetType() == String::typeid)) {
            return "'" + src->ToString()->Replace("'", "\\'") + "'";
        }
        if (src->GetType()->IsSubclassOf(DateTime::typeid) || (src->GetType() == DateTime::typeid)) {
            //Console::WriteLine("DateTime");
            DateTime^ datetime = safe_cast<DateTime^>(src);
            return "'" + datetime->Year + "-" + Convert::ToString(datetime->Month)->PadLeft(2)->Replace(" ", "0") + "-" + Convert::ToString(datetime->Day)->PadLeft(2)->Replace(" ", "0") + "'";
        }
        if (src->GetType()->IsSubclassOf(Int16::typeid) || (src->GetType() == Int16::typeid) ||
            src->GetType()->IsSubclassOf(Int32::typeid) || (src->GetType() == Int32::typeid) ||
            src->GetType()->IsSubclassOf(Int64::typeid) || (src->GetType() == Int64::typeid) ||
            src->GetType()->IsSubclassOf(UInt16::typeid) || (src->GetType() == UInt16::typeid) ||
            src->GetType()->IsSubclassOf(UInt32::typeid) || (src->GetType() == UInt32::typeid) ||
            src->GetType()->IsSubclassOf(UInt64::typeid) || (src->GetType() == UInt64::typeid)) {
            return "'" + src->ToString() + "'";
        }
        if (src->GetType()->IsSubclassOf(Decimal::typeid) || (src->GetType() == Decimal::typeid) ||
            src->GetType()->IsSubclassOf(Double::typeid) || (src->GetType() == Double::typeid) ||
            src->GetType()->IsSubclassOf(Single::typeid) || (src->GetType() == Single::typeid)) {
            return "'" + src->ToString()->Replace(",", ".") + "'";
        }
        //Console::WriteLine("Unknown");
        return "'" + src->ToString()->Replace("'", "\\'") + "'";
    }

}
