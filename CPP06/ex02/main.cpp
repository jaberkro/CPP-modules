#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base * generate(void)
{
	Base *basePointer;

	switch(std::rand() % 3)
	{
		case 0:
			basePointer = dynamic_cast<Base *>(new A);
		case 1:
			basePointer = dynamic_cast<Base *>(new B);
		case 2:
			basePointer = dynamic_cast<Base *>(new C);
	}
	return (basePointer);
}

// void identify(Base* p)
// {
// 	(void)p;

// }

// void identify(Base& p)
// {
// 	(void)p;
// }


int	main(void)
{
	std::srand(std::time(nullptr));

	Base	*ptr;

	ptr = generate();

	return (0);
}
