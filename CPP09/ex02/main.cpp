#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>

int main (int argc, char **argv)
{
	PmergeMe	pmergeMe;

	try {
		pmergeMe.prepareContainers(argc, argv);

		std::cout << "Before:  ";
		pmergeMe.show();

	    std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
		pmergeMe.sortVector(2);
   		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		pmergeMe.setSortedFalse();
		std::chrono::high_resolution_clock::time_point begin2 = std::chrono::high_resolution_clock::now();
		pmergeMe.sortDeque(2);
		std::chrono::high_resolution_clock::time_point end2 = std::chrono::high_resolution_clock::now();

		std::cout << "After:   ";
		pmergeMe.show();

    	std::chrono::microseconds elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    	std::chrono::microseconds elapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);
		std::cout << "Time to process a range of " << pmergeMe.getSize() << " elements with std::vector : " << elapsed.count() <<" us" << std::endl;
		std::cout << "Time to process a range of " << pmergeMe.getSize() << " elements with std::deque : " << elapsed2.count() <<" us" << std::endl;
		
		// pmergeMe.test();
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
