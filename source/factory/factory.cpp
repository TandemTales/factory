#include "factory.h"
#include "manager.h"
#include <string>

namespace tt
{
	c_factory::~c_factory()
	{
		for (auto& [key, value] : m_managers)
		{
			delete value;
		}
	}

	void c_factory::load(std::string const& file_name)
	{
		m_data.load(file_name);
		if (m_data.is_array())
		{
			for (c_json data : m_data)
			{
				if (data["type"].is_string())
				{
					c_hash manager_type = c_hash(data["type"].get<std::string>());
					auto it = m_managers.find(manager_type);
					if (it != m_managers.end())
					{
						it->second->load(data);
					}
				}
			}
		}
	}

	void c_factory::create()
	{
		for (auto& [key, value] : m_managers)
		{
			value->create();
		}
	}
}