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
			std::cout << "Generate C" << std::endl;
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
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "This is A" << std::endl;
	}
	catch (...)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "This is B" << std::endl;
		}
		catch (...)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "This is C" << std::endl;
			}
			catch (...)
			{
			}
		}
	}
}
