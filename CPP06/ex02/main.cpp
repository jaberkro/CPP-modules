#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base * generate(void)
{
	Base *basePointer = NULL;

	switch(std::rand() % 3)
	{
		case 0:
			basePointer = dynamic_cast<Base *>(new A);
			break ;
		case 1:
			basePointer = dynamic_cast<Base *>(new B);
			break ;
		case 2:
			basePointer = dynamic_cast<Base *>(new C);
			break ;
	}
	return (basePointer);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p) == p)
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(p) == p)
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p) == p)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(std::bad_cast)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(std::bad_cast)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch(std::bad_cast)
			{
				std::cout << "Error: type does not respond to A, B or C" << std::endl;
			}	
		}
	}
}

int	main(void)
{
	std::srand(std::time(nullptr));

	Base	*random1;
	Base	*random2;
	Base	*random3;
	Base	*random4;

	random1 = generate();
	random2 = generate();
	random3 = generate();
	random4 = generate();
	identify(random1);
	identify(*random1);
	identify(random2);
	identify(*random2);
	identify(random3);
	identify(*random3);
	identify(random4);
	identify(*random4);

	return (0);
}
