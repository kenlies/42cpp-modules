#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <time.h>

Base * generate(void)
{
	srand(time(0));
	int choice = rand() % 3;

	switch (choice)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return nullptr;
}

void identify(Base* p)
{
	A* a = dynamic_cast<A *>(p);
	if (a != NULL)
	{
		std::cout << "type: A" << "\n";
		return ;
	}
	B* b = dynamic_cast<B *>(p);
	if (b != NULL)
	{
		std::cout << "type: B" << "\n";
		return ;
	}
	C* c = dynamic_cast<C *>(p);
	if (c != NULL)
	{
		std::cout << "type: C" << "\n";
		return ;
	}
	std::cout << "unknown type" << "\n";
}

void identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A &>(p);
		std::cout << "type: A" << "\n";
	}
	catch (std::exception & e)
	{
		try
		{
			B b = dynamic_cast<B &>(p);
			std::cout << "type: B" << "\n";
		}
		catch (std::exception & e)
		{
			try
			{
				C c = dynamic_cast<C &>(p);
				std::cout << "type: C" << "\n";
			}
			catch (std::exception & e)
			{
				std::cout << "unknown type" << "\n";
			}
		}
	}
}


int main ()
{

	Base *base = generate();
	identify(base);
	identify(*base);

	delete base;

	return 0;
}