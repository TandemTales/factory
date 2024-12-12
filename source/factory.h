#pragma once

#include "json.h"
#include <string>

namespace tt
{
	class c_factory
	{
	public:
		void load(std::string const& file_name) { m_data.load(file_name); }

	private:
		c_json m_data;
	};
}
