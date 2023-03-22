#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

Serializer::Serializer(void)
{
	std::cout << "Default constructor called on Serializer" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << "Copy constructor called on Serializer" << std::endl;
	*this = src;
}

Serializer& Serializer::operator=(const Serializer &src)
{
	std::cout << "Copy assignment operator called on Serializer" << std::endl;
	(void)src;
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << "Destructor called on Serializer" << std::endl;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
