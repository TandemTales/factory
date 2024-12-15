#include "factory/factory.h"
#include "factory/manager.h"
#include "core/log.h"

using namespace tt;

class c_test_manager : public c_manager
{
public:
	static constexpr c_hash manager_type = "test"_h;

public:
	void create() override
	{
		logln("c_test_manager::create");
	};

	c_hash get_type() const override { return manager_type; }
};

int main()
{
	c_factory factory;
	factory.register_manager<c_test_manager>();
	factory.load("test.json");
	factory.create();

	return 0;
}
