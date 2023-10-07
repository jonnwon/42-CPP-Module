#include "Base.hpp"

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main()
{
	Base *objs;

	objs = generate();
	identify(objs);
	identify(*objs);

	return 0;
}
