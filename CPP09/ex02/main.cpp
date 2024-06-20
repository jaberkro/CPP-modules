#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <stdio.h>
#include <cstdlib>

int	positiveSequence(int argc, char **argv)
{
	int i = 1;

	while (i < argc)
	{
		int	j = 0;
		while (argv[i][j])
		{
			if (!isdigit(argv[i][j]) && argv[i][j] != ' ')
			{
				std::cout << argv[i];
				return (0);
			}
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
	PmergeMe pmergeMe;

	if (argc < 2)
		return (errorReturn("not enough arguments", 1));
	if (!positiveSequence(argc, argv))
		return (errorReturn("input must be positive integers only", 1));
	try {
		pmergeMe.fillContainers(argc, argv);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	//todo: check for doubles
	pmergeMe.start();
	pmergeMe.sortVector(2);
	pmergeMe.sortDeque(2);
	pmergeMe.finish();
	// pmergeMe.test();
	return (EXIT_SUCCESS);
}
