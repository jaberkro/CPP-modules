#include "Serializer.hpp"
#include <iostream>

void	testLeaks(void)
{
	std::cout << std::endl;
	system("leaks serializer -q");
}

int	main(void)
{
	Data		data;
	Data		*dataPointer;
	uintptr_t	uintPointer;
	Data		*newPointer;

	data.value = 10;
	data.secondValue = 42;
	dataPointer = &data;
	std::cout << std::endl;
	std::cout << "address of d: " << &data << std::endl;
	std::cout << "value of d: " << data.value << std::endl;
	std::cout << "second value of d: " << data.secondValue << std::endl;
	std::cout << "address of dataPointer: " << &dataPointer << std::endl;
	std::cout << "address dataPointer points to: " << dataPointer << std::endl;
	std::cout << "value at address dataPointer points to: " << dataPointer->value << std::endl;
	std::cout << "second value at address dataPointer points to: " << dataPointer->secondValue << std::endl;

	std::cout << "\nSERIALIZING..." << std::endl;
	uintPointer = Serializer::serialize(dataPointer);
	std::cout << "address of p: " << &uintPointer << std::endl;
	std::cout << "value of p: " << uintPointer << std::endl;

	std::cout << "\nDESERIALIZING..." << std::endl;
	newPointer = Serializer::deserialize(uintPointer);
	std::cout << "address of newPointer: " << &newPointer << std::endl;
	std::cout << "address np points to: " << newPointer << std::endl;
	std::cout << "value of np: " << newPointer->value << std::endl;
	std::cout << "second value of np: " << newPointer->secondValue << std::endl;
	std::cout << std::endl;

	atexit(testLeaks);
	return (0);	
}
