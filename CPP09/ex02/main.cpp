#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>

int	fillContainers(int argc, char **argv, int size)
{
	std::vector<int>			v;
	// std::array<int, size>	a;
	long						input;
	int i = 1;
	(void)size;
	while (i < argc)
	{
		//try
		input = atol(argv[i]);
		//catch
		if (input >= 0 && input <= 2147483647)
		{
			//try
			// a.at(i - 1) = static_cast<int>(input);
			v.push_back(static_cast<int>(input));
			//catch
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	countSize(int argc, char **argv)
{
	int i = 1;

	while (i < argc)
	{
		int	j = 0;
		while (argv[i][j])
		{
			if (!isdigit(argv[i][j]) && argv[i][j] != ' ')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	positiveSequence(int argc, char **argv)
{
	int i = 1;

	while (i < argc)
	{
		int	j = 0;
		while (argv[i][j])
		{
			if (!isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	errorReturn(std::string message, int returnValue)
{
	std::cout << "Error: " << message << std::endl;
	return (returnValue);
}

int main (int argc, char **argv)
{
	if (argc < 2)
		return (errorReturn("not enough arguments", 1));
	if (!positiveSequence(argc, argv))
		return (errorReturn("input must be positive integers only", 1));
	if (!fillContainers(argc, argv, argc - 1))
		return (errorReturn("not possible to convert input to integers", 1));;
	return (0);
}
