#pragma once

#include "json/json.h"
#include "core/hash.h"
#include <unordered_map>

namespace tt
{
	class c_manager
	{
	public:
		bool load(c_json& data);
		virtual void create() = 0;
		c_json* get_data(c_hash key);
		virtual c_hash get_type() const = 0;

	private:
		std::unordered_map<c_hash, c_json, s_hash_hasher> m_data;
	};
}
