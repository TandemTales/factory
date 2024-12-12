#pragma once

#include "json.h"
#include "core/hash.h"

namespace tt
{
	class c_blueprint
	{
	public:
		void load(std::string const& file_name) { m_data.load(file_name); }
		virtual void create() = 0;
		virtual c_hash get_hash() = 0;

	private:
		c_json m_data;
	};
}
