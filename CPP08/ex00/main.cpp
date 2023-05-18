#include <iostream>
#include <vector>
#include <array>
#include "easyfind.hpp"

int main (void)
{
	std::vector<int> v;

	v.push_back(30);
	v.push_back(12);
	v.push_back(1);

	try
	{
		std::cout << "trying to find 21: ";
		easyfind(v, 21);
		std::cout << "found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "trying to find 1: ";
		easyfind(v, 1);
		std::cout << "found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "trying to find 3: ";
		easyfind(v, 3);
		std::cout << "found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::array<int, 10> a;

	for (int i = 0; i < 10; i++)
		a.at(i) = i;

	try
	{
		std::cout << "trying to find 21: ";
		easyfind(a, 21);
		std::cout << "found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "trying to find 1: ";
		easyfind(a, 1);
		std::cout << "found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "trying to find 3: ";
		easyfind(a, 3);
		std::cout << "found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
