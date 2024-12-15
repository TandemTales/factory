#pragma once

#include "blueprint.h"
#include "json/json.h"
#include "core/hash.h"
#include <string>
#include <unordered_map>

namespace tt
{
	class c_factory
	{
	public:
		~c_factory();
		void load(std::string const& file_name);
		void create();

		template<class T>
		void register_blueprint()
		{
			m_blueprints[T::get_hash()] = new T();
		}

	private:
		c_json m_data;
		std::unordered_map<c_hash, c_blueprint*, s_hash_hasher> m_blueprints;
	};
}
