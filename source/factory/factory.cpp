#include "factory.h"
#include "blueprint.h"
#include <string>

namespace tt
{
	c_factory::~c_factory()
	{
		for (auto& [key, value] : m_blueprints)
		{
			delete value;
		}
	}

	void c_factory::load(std::string const& file_name)
	{
		m_data.load(file_name);
		if (m_data.is_array())
		{
			for (c_json blueprint_data : m_data)
			{
				if (blueprint_data["type"].is_string())
				{
					c_hash blueprint_type = c_hash(blueprint_data["type"].get<std::string>());
					auto it = m_blueprints.find(blueprint_type);
					if (it != m_blueprints.end())
					{
						it->second->load(blueprint_data);
					}
				}
			}
		}
	}

	void c_factory::create()
	{
		for (auto& [key, value] : m_blueprints)
		{
			value->create();
		}
	}
}