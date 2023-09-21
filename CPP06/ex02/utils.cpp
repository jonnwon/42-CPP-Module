#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int		n;
	Base	*res;

    std::srand(std::time(0));
	n = rand() % 3;

	switch(n)
	{
		case 0:
		{
			std::cout << "Generate A" << std::endl;
			res = new A;
			break;
		}
		case 1:
		{
			std::cout << "Generate B" << std::endl;
			res = new B;
			break;
		}
		case 2:
		{
			std::cout << "Generate c" << std::endl;
			res = new C;
			break;
		}
	}
	return res;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "This is A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "This is B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "This is C" << std::endl;
	}
}

void identify(Base& p)
{
	if (dynamic_cast<A*>(&p))
	{
		std::cout << "This is A" << std::endl;
	}
	else if (dynamic_cast<B*>(&p))
	{
		std::cout << "This is B" << std::endl;
	}
	else if (dynamic_cast<C*>(&p))
	{
		std::cout << "This is C" << std::endl;
	}
}
