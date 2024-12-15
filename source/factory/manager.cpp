#include "manager.h"
#include <cassert>

namespace tt
{
	bool c_manager::load(c_json& data)
	{
		if (!data["type"].is_string())
		{
			return false;
		}

		c_hash manager_type = c_hash(data["type"].get<std::string>());
		if (manager_type != get_type())
		{
			return false;
		}

		if (!data["name"].is_string())
		{
			return false;
		}

		m_data[c_hash(data["name"].get<std::string>())] = data;
		return true;
	}

	c_json* c_manager::get_data(c_hash key)
	{
		auto it = m_data.find(key);
		if (it != m_data.end())
		{
			return &it->second;
		}
		return nullptr;
	}
}
