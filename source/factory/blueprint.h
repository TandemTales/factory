#pragma once

#include "json/json.h"
#include "core/hash.h"

namespace tt
{
	class c_blueprint
	{
	public:
		void load(c_json const& data) { m_data = data; }
		virtual void create() = 0;
		c_json const& get_data() const { return m_data; }

	private:
		c_json m_data;
	};
}
