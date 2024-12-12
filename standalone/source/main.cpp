#include "factory.h"

using namespace tt;

int main()
{
	c_factory factory;
	factory.load("test.json");
	return 0;
}
