#include "factory/factory.h"
#include "factory/blueprint.h"
#include "core/log.h"

using namespace tt;

class c_test_blueprint : public c_blueprint
{
public:
	static c_hash get_hash()
	{
		return "test"_h;
	}

public:
	virtual void create()
	{
		logln("c_test_blueprint::create");
	};
};

int main()
{
	c_factory factory;
	factory.register_blueprint<c_test_blueprint>();
	factory.load("test.json");
	factory.create();

	return 0;
}
