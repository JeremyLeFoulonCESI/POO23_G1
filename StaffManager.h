#pragma once
#include "Manager.h"
#include "Struct.h"

using namespace structure;

namespace Services {
	ref class StaffManager: public Manager {
	public:
		StaffManager();
		StaffMemberData addStaff(StaffMemberData);
		StaffMemberData getStaff(int id);
		StaffMemberData editStaff(int id, StaffMemberData _new);
		void removeStaff(int id);
		int count();
		DataTable^ getAllStaff();
};
}