#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <locale>
#include <ctime>
#include <chrono>

void	checkPositiveSequence(int argc, char **argv)
{
	int i = 1;

	while (i < argc)
	{
		int	j = 0;
		while (argv[i][j])
		{
			if (!isdigit(argv[i][j]) && argv[i][j] != ' ')
			{
				throw PmergeMe::NotAPositiveIntegerException();
			}
			j++;
		}
		i++;
	}
}

int main (int argc, char **argv)
{
	PmergeMe pmergeMe;

	try {
		if (argc < 2)
			throw PmergeMe::NotEnoughArgumentsException();
		checkPositiveSequence(argc, argv);
		pmergeMe.fillContainers(argc, argv);
		pmergeMe.start();
	    std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
		pmergeMe.sortVector(2);
   		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		std::chrono::high_resolution_clock::time_point begin2 = std::chrono::high_resolution_clock::now();
		pmergeMe.sortDeque(2);
		std::chrono::high_resolution_clock::time_point end2 = std::chrono::high_resolution_clock::now();
		pmergeMe.finish();
    	std::chrono::microseconds elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    	std::chrono::microseconds elapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);
		std::cout << "Time to process a range of " << pmergeMe.getSize() << " elements with std::vector : " << elapsed.count() <<" us" << std::endl;
		std::cout << "Time to process a range of " << pmergeMe.getSize() << " elements with std::deque : " << elapsed2.count() <<" us" << std::endl;
		pmergeMe.test();
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
