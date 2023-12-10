#pragma once

namespace Components {

	ref class SqlData
	{
	public:
		static String^ ObjectToSql(Object^ src);
	};

}

