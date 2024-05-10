#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <iterator>
#include "easyfind.hpp"

template<typename T>
void testPresent(T &t, int number) {
	std::cout << "Testing if the number [" << number << "] is present: ";
	try
	{
		std::cout << *(easyfind(t, number)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main (void)
{
	{
		std::vector<int> v;

		v.push_back(30);
		v.push_back(12);
		v.push_back(1);

		std::cout << "Vector easyfind:" << std::endl;
		testPresent(v, 21);
		testPresent(v, 1);
		testPresent(v, 3);
		std::cout << std::endl;
	}
	{
		std::array<int, 10> a;

		for (int i = 0; i < 10; i++)
		{
			a.at(i) = i;
		}	

		std::cout << "Array easyfind:" << std::endl;
		testPresent(a, 21);
		testPresent(a, 1);
		testPresent(a, 3);
		std::cout << std::endl;
	}
	{
		std::deque<int> d;

		for (int i = 0; i < 30; i++)
		{
			d.push_back(i);	
		}	

		std::cout << "Deque easyfind:" << std::endl;
		testPresent(d, 21);
		testPresent(d, 1);
		testPresent(d, 3);
		std::cout << std::endl;
	}
	return (0);
}
