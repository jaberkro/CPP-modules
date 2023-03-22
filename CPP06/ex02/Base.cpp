#include "Base.hpp"
#include <iostream>

Base::~Base(void)
{
	std::cout << "Destructor called on Base" << std::endl;
}
