#pragma once

#include "manager.h"
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
		void register_manager()
		{
			m_managers[T::manager_type] = new T();
		}

		template<class T>
		T* get_manager()
		{
			auto it = m_managers.find(T::manager_type);
			if (it != m_managers.end())
			{
				return static_cast<T*>(it->second);
			}
			return nullptr;
		}

	private:
		c_json m_data;
		std::unordered_map<c_hash, c_manager*, s_hash_hasher> m_managers;
	};
}
