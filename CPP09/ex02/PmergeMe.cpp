#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <iterator>

PmergeMe::PmergeMe(void)
{
	// std::cout << "Default constructor called on PmergeMe" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	// std::cout << "Copy constructor called on PmergeMe" << std::endl;
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src)
{
	// std::cout << "Copy assignment operator called on PmergeMe" << std::endl;
	// this->_array = src._array;
	this->_vector = src._vector;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	// std::cout << "Destructor called on PmergeMe" << std::endl;
}

const char* PmergeMe::NotAnIntegerException::what() const throw()
{
	return ("Exception: Not possible to convert input to integer");
}

const char* PmergeMe::NotEnoughArgumentsException::what() const throw()
{
	return ("Exception: Not enough arguments");
}

static void print(int i) 
{
	std::cout << i << " ";
}

int PmergeMe::fillContainers(int argc, char **argv)
{
	long	input;
	int		i = 1;

	while (i < argc)
	{
		size_t j = 0;
		std::string s = argv[i];
		if (s.length() == 0)
		{
			i++;
			continue;
		}
		while (j < s.length())
		{
			std::string newInt = "";
			while (j < s.length() && s.at(j) != ' ')
			{
				newInt += s.at(j);
				j++;
			}
			if (newInt.length() > 0)
			{
				try {
					input = stol(newInt);
				}
				catch (const std::exception& e) {
					throw PmergeMe::NotAnIntegerException();
				}
				if (input >= 0 && input <= 2147483647)
				{
					this->_vector.push_back(static_cast<int>(input));
					this->_deque.push_back(static_cast<int>(input));
					this->_sorted.push_back(false);
				}
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	if (this->_vector.size() == 0) {
		throw PmergeMe::NotEnoughArgumentsException();
	}
	return (1);
}

void	PmergeMe::createJacobsthal()
{
	size_t first = 0;
	size_t second = 1;
	size_t index = 0;
	this->_jacobsthalVector.push_back(1);
	while (index < this->_vector.size())
	{
		size_t newJacobsthal = first * 2 + second;
		this->_jacobsthalVector.push_back(newJacobsthal);
		index += newJacobsthal;
		first = second;
		second = newJacobsthal;
	}
	this->_jacobsthalVector.push_back(first * 2 + second);
} 

void	PmergeMe::start() 
{
	std::cout << "Before vector: ";
	for_each(this->_vector.begin(), this->_vector.end(), print);
	std::cout << std::endl;
	createJacobsthal();
}

void	PmergeMe::finish()
{
	std::cout << "After vector: ";
	for_each(this->_vector.begin(), this->_vector.end(), print);
	std::cout << std::endl;
	std::cout << "After deque:  ";
	for_each(this->_deque.begin(), this->_deque.end(), print);
	std::cout << std::endl;
}

template <typename T>
void	PmergeMe::show(T &t)
{
	std::cout << "Sorted: ";
	for_each(this->_sorted.begin(), this->_sorted.end(), print);
	std::cout << std::endl;
	std::cout << "After:  ";
	for_each(t.begin(), t.end(), print);
	std::cout << std::endl;
}

template <typename T>
void	PmergeMe::movePair(T &t, size_t from, size_t to, size_t range)
{
	// std::cout << "Moving \033[1;35m" << t.at(from) << "\033[0m from index " << from << " to index " << to << std::endl;
	T tmp;
	tmp.insert(tmp.begin(), t.begin() + from, t.begin() + from + range);
	t.erase(t.begin() + from, t.begin() + from + range);
	t.insert(t.begin() + to, tmp.begin(), tmp.end());
	std::vector<bool> tmpBool;
	tmpBool.insert(tmpBool.begin(), this->_sorted.begin() + from, this->_sorted.begin() + from + range);
	this->_sorted.erase(this->_sorted.begin() + from, this->_sorted.begin() + from + range);
	this->_sorted.insert(this->_sorted.begin() + to, tmpBool.begin(), tmpBool.end());
	this->_sorted.at(to) = true;
}

size_t PmergeMe::findMiddle(size_t sortedUntil, size_t minIndex, size_t maxIndex, size_t pairSize)
{
	size_t options = 0;
	size_t index = minIndex;

	for (size_t i = minIndex; i <= maxIndex; i++)
	{
		if (this->_sorted.at(i) == true)
			options++;
	}
	// if (pairSize == 2)
	options /= 2;
	// std::cout << "options: " << options << ", ";
	while (options > 0)
	{
		index++;
		while (this->_sorted.at(index) != true)
			index++;
		options--;
	}
	// if (pairSize == 2)
	// std::cout << "Min: " << minIndex << ", max: " << maxIndex << ", middle: " << index << std::endl;
	(void)sortedUntil;
	(void)pairSize;
	return (index);
}

template <typename T>
size_t PmergeMe::findCorrectLocation(T &t, size_t toSortIndex, size_t pairSize, size_t sortedUntil, size_t min, size_t max)
{
	size_t middle = findMiddle(sortedUntil, min, max, pairSize);
	// 	std::cout << "to sort: " << t.at(toSortIndex) << ", min: " << min << ", middle: " << middle << ", max: " << max << std::endl;
	if (middle == max && t.at(toSortIndex) < t.at(min))
		return(min);
	else if (middle == max)
		return(max);
	else if (middle == min)
		return (min);
	if (t.at(toSortIndex) > t.at(middle))
	{
		// std::cout << "Higher!" << std::endl;
		return findCorrectLocation(t, toSortIndex, pairSize, sortedUntil, middle, max);
	}	
	else
	{
		// std::cout << "Lower!" << std::endl;
		return findCorrectLocation(t, toSortIndex, pairSize, sortedUntil, min, middle);
	}	
}

template <typename T>
void PmergeMe::sortSmallestInPairs(T &t, size_t pairSize) 
{
	size_t	lastJacobsthal = 0;
	size_t	jacobsthalIndex = 1;
	size_t	pairIndex = 1;
	size_t	toSortIndex = pairSize / 2;
	size_t	sortedUntil = lastJacobsthal * pairSize;
	for (size_t i = 0; i < t.size(); i += pairSize)
	{
		this->_sorted.at(i) = true;
	}
	while (toSortIndex < t.size() - t.size() % pairSize)
	{
		// std::cout << "pairIndex: " << pairIndex << ", lastJacobsthal: " << lastJacobsthal << ", toSortIndex: " << toSortIndex << std::endl;
		movePair(t, toSortIndex, findCorrectLocation(t, toSortIndex, pairSize, sortedUntil, 0, toSortIndex - pairSize / 2), pairSize/2);
		// show(t);
		pairIndex--;
		while (pairIndex != lastJacobsthal && this->_sorted.at(toSortIndex) == true)
		{
			toSortIndex -= pairSize / 2;
			sortedUntil += pairSize / 2; //todo: remove later
			// std::cout << " lowering index to: " << toSortIndex;
		}
		// std::cout << std::endl;
		if (pairIndex == lastJacobsthal)
		{
			// std::cout << "moving up the jacobsthal number" << std::endl;
			lastJacobsthal = this->_jacobsthalVector.at(jacobsthalIndex);
			jacobsthalIndex++;		
			pairIndex = this->_jacobsthalVector.at(jacobsthalIndex);
			toSortIndex = pairIndex * pairSize - pairSize / 2;
			sortedUntil = lastJacobsthal * pairSize;
			
			while (pairIndex > lastJacobsthal && toSortIndex > t.size() - t.size() % pairSize - 1)
			{
				pairIndex--;
				toSortIndex -= pairSize;
			}
			if (pairIndex == lastJacobsthal)
				break;
		}
		// if (pairSize == 2)
	} 
	size_t stragglerSize = t.size() % pairSize;
	if (stragglerSize >= pairSize / 2)
	{
		size_t stragglerStart = t.size() - stragglerSize;
		// std::cout << "Straggler! " << stragglerStart <<std::endl;
		movePair(t, stragglerStart, findCorrectLocation(t, stragglerStart, pairSize, lastJacobsthal * pairSize, 0, stragglerStart), pairSize / 2);
	}
	// show(t);
}

template <typename T>
void	PmergeMe::swapPairs(T &t, size_t pairSize)
{
	for (typename T::iterator it = t.begin(); it < t.end() - 1; it += pairSize)
	{
		if (it + pairSize / 2 < t.begin() + t.size() - t.size() % pairSize && *it < *(it + pairSize / 2)) // sometimes t.end() - 1, sometimes just t.end() needed
		{	
			std::swap_ranges(it, it + pairSize / 2, it + pairSize / 2);
		}
	}
	// show(t);
}

void	PmergeMe::sortVector(size_t pairSize)
{
	// std::cout << "\033[1;33mNew recursion, pairsize: " << pairSize << "\033[0m" << std::endl;
	if (pairSize > this->_vector.size())
	{
		// std::cout << "\033[1;32mReturning from recursion, pairsize: " << pairSize << "\033[0m" << std::endl;
		return ;
	}
	swapPairs(this->_vector, pairSize);
	sortVector(pairSize * 2);
	// std::cout << "\033[1;32mReturn from recursion, pairsize: " << pairSize << "\033[0m" << std::endl;
	sortSmallestInPairs(this->_vector, pairSize);
	// std::cout << std::endl;
	for(size_t i = 0; i < this->_sorted.size(); i++)
		this->_sorted.at(i) = false;
}

void	PmergeMe::sortDeque(size_t pairSize)
{		
	// std::cout << "\033[1;33mNew recursion, pairsize: " << pairSize << "\033[0m" << std::endl;	
	// show (this->_deque);
	if (pairSize > this->_deque.size())
	{
		// std::cout << "\033[1;32mReturning from recursion, pairsize: " << pairSize << "\033[0m" << std::endl;
		return ;
	}
	swapPairs(this->_deque, pairSize);
	sortDeque(pairSize * 2);
	// std::cout << "\033[1;32mReturn from recursion, pairsize: " << pairSize << "\033[0m" << std::endl;
	sortSmallestInPairs(this->_deque, pairSize);
	// show(this->_deque);
}

void PmergeMe::test(void)
{
	bool passed = true;
	int last = -1;
	for (size_t i = 0; i < this->_vector.size(); i++)
	{
		if (this->_vector.at(i) > last)
			last = this->_vector.at(i);
		else
		{
			std::cout << "\033[1;31mFAILURE! NOT SORTED DEQUE!\033[0m " << this->_deque.at(i) << std::endl;
			passed = false;
		}		
	}
	last = -1;
	for (size_t i = 0; i < this->_deque.size(); i++)
	{
		if (this->_deque.at(i) > last)
			last = this->_deque.at(i);
		else
		{
			std::cout << "\033[1;31mFAILURE! NOT SORTED DEQUE!\033[0m " << this->_deque.at(i) << std::endl;
			passed = false;
		}		
	}
	if (passed == true)
		std::cout << "\033[1;32mOK\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mKO\033[0m" << std::endl;
}
