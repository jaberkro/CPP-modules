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
	this->_deque = src._deque;
	this->_vector = src._vector;
	this->_sorted = src._sorted;
	this->_jacobsthalVector = src._jacobsthalVector;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	// std::cout << "Destructor called on PmergeMe" << std::endl;
}

const char* PmergeMe::NotAPositiveIntegerException::what() const throw()
{
	return ("Exception: Input should be positive integers");
}

const char* PmergeMe::DuplicateInputException::what() const throw()
{
	return ("Exception: Duplicate in input");
}

const char* PmergeMe::NotEnoughArgumentsException::what() const throw()
{
	return ("Exception: Not enough arguments");
}

void	PmergeMe::setSortedFalse(void)
{
	for (size_t i = 0; i < this->_vector.size(); i++)
	{
		if (this->_sorted.size() < this->_vector.size())
			this->_sorted.push_back(false);
		else
			this->_sorted.at(i) = false;
	}
}

static void	checkPositiveSequence(int argc, char **argv)
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

void	PmergeMe::storeInput(long input)
{
	if (input >= 0 && input <= 2147483647)
	{
		if (std::find(this->_vector.begin(), this->_vector.end(), input) != this->_vector.end())
			throw PmergeMe::DuplicateInputException();
		this->_vector.push_back(static_cast<int>(input));
		this->_deque.push_back(static_cast<int>(input));
	}
	else
		throw PmergeMe::NotAPositiveIntegerException();
}

void	PmergeMe::parseArgument(std::string s)
{
	long	input;
		
	for (size_t i  = 0; i < s.length(); i++)
	{
		std::string newInt = "";
		while (i < s.length() && s.at(i) != ' ')
		{
			newInt += s.at(i);
			i++;
		}
		if (newInt.length() > 0)
		{
			try 
			{
				input = stol(newInt);
			}
			catch (const std::exception& e) 
			{
				throw PmergeMe::NotAPositiveIntegerException();
			}
			storeInput(input);
		}
	}
}

void PmergeMe::prepareContainers(int argc, char **argv)
{
	int		i = 1;

	if (argc < 2)
		throw PmergeMe::NotEnoughArgumentsException();
	checkPositiveSequence(argc, argv);
	while (i < argc)
	{
		std::string s = argv[i];
		if (s.length() == 0)
		{
			i++;
			continue;
		}
		parseArgument(s);
		i++;
	}
	if (this->_vector.size() == 0) {
		throw PmergeMe::NotEnoughArgumentsException();
	}
	createJacobsthal();
	setSortedFalse();
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

static void print(int i) 
{
	std::cout << i << " ";
}

void	PmergeMe::show()
{
	for_each(this->_vector.begin(), this->_vector.end(), print);
	std::cout << std::endl;
}

template <typename T>
void	PmergeMe::movePair(T &t, size_t from, size_t to, size_t range)
{
	T tmpT;
	std::vector<bool> tmpBool;

	tmpT.insert(tmpT.begin(), t.begin() + from, t.begin() + from + range);
	t.erase(t.begin() + from, t.begin() + from + range);
	t.insert(t.begin() + to, tmpT.begin(), tmpT.end());
	tmpBool.insert(tmpBool.begin(), this->_sorted.begin() + from, this->_sorted.begin() + from + range);

	this->_sorted.erase(this->_sorted.begin() + from, this->_sorted.begin() + from + range);
	this->_sorted.insert(this->_sorted.begin() + to, tmpBool.begin(), tmpBool.end());
	this->_sorted.at(to) = true;
}

size_t PmergeMe::findMiddle(size_t minIndex, size_t maxIndex)
{
	size_t options = 0;
	size_t index = minIndex;

	for (size_t i = minIndex; i <= maxIndex; i++)
	{
		if (this->_sorted.at(i) == true)
			options++;
	}
	options /= 2;
	while (options > 0)
	{
		index++;
		while (this->_sorted.at(index) != true)
			index++;
		options--;
	}
	return (index);
}

template <typename T>
size_t PmergeMe::findCorrectLocation(T &t, size_t toSortIndex, size_t pairSize, size_t min, size_t max)
{
	size_t middle = findMiddle(min, max);
	if (middle == max && t.at(toSortIndex) < t.at(min))
		return(min);
	else if (middle == max)
		return(max);
	else if (middle == min)
		return (min);
	if (t.at(toSortIndex) > t.at(middle))
		return findCorrectLocation(t, toSortIndex, pairSize, middle, max);
	else
		return findCorrectLocation(t, toSortIndex, pairSize, min, middle);
}

template <typename T>
void PmergeMe::placeStraggler(T &t, size_t pairSize) 
{
	size_t stragglerSize = t.size() % pairSize;
	if (stragglerSize >= pairSize / 2)
	{
		size_t stragglerStart = t.size() - stragglerSize;
		movePair(t, stragglerStart, findCorrectLocation(t, stragglerStart, pairSize, 0, stragglerStart), pairSize / 2);
	}
}

size_t PmergeMe::findNextIndexToSort(size_t toSortIndex, size_t pairSize, size_t pairIndex, size_t lastJacobsthal)
{
	while (pairIndex != lastJacobsthal && this->_sorted.at(toSortIndex) == true)
	{
		toSortIndex -= pairSize / 2;
	}
	return(toSortIndex);
}

template <typename T>
void PmergeMe::sortSmallestOfPairs(T &t, size_t pairSize) 
{
	size_t	lastJacobsthal = 0;
	size_t	jacobsthalIndex = 1;
	size_t	pairIndex = 1;
	size_t	toSortIndex = pairSize / 2;

	for (size_t i = 0; i < t.size(); i += pairSize)
	{
		this->_sorted.at(i) = true;
	}
	while (toSortIndex < t.size() - t.size() % pairSize)
	{
		movePair(t, toSortIndex, findCorrectLocation(t, toSortIndex, pairSize, 0, toSortIndex - pairSize / 2), pairSize/2);
		pairIndex--;
		toSortIndex = findNextIndexToSort(toSortIndex, pairSize, pairIndex, lastJacobsthal);
		if (pairIndex == lastJacobsthal)
		{
			lastJacobsthal = this->_jacobsthalVector.at(jacobsthalIndex);
			jacobsthalIndex++;		
			pairIndex = this->_jacobsthalVector.at(jacobsthalIndex);
			toSortIndex = pairIndex * pairSize - pairSize / 2;

			while (pairIndex > lastJacobsthal && toSortIndex > t.size() - t.size() % pairSize - 1)
			{
				pairIndex--;
				toSortIndex -= pairSize;
			}
			if (pairIndex == lastJacobsthal)
				break;
		}
	}
	placeStraggler(t, pairSize);
}

template <typename T>
static bool	arrivedAtStraggler(T &t, size_t pairSize, typename T::iterator it)
{
	return (it + pairSize / 2 >= t.begin() + t.size() - t.size() % pairSize);
}

template <typename T>
void	PmergeMe::swapPairs(T &t, size_t pairSize)
{
	for (typename T::iterator it = t.begin(); it < t.end() - 1; it += pairSize)
	{
		if (!arrivedAtStraggler(t, pairSize, it) && *it < *(it + pairSize / 2))
		{	
			std::swap_ranges(it, it + pairSize / 2, it + pairSize / 2);
		}
	}
}

void	PmergeMe::sortVector(size_t pairSize)
{
	if (pairSize > this->_vector.size())
		return ;
	swapPairs(this->_vector, pairSize);
	sortVector(pairSize * 2);
	sortSmallestOfPairs(this->_vector, pairSize);
}

void	PmergeMe::sortDeque(size_t pairSize)
{		
	if (pairSize > this->_deque.size())
		return ;
	swapPairs(this->_deque, pairSize);
	sortDeque(pairSize * 2);
	sortSmallestOfPairs(this->_deque, pairSize);
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
			std::cout << "\033[1;31mFAILURE! NOT SORTED VECTOR!\033[0m " << this->_deque.at(i) << std::endl;
			passed = false;
		}
		if (this->_vector.at(i) != this->_deque.at(i))
		{
			std::cout << "\033[1;31mFAILURE! VECTOR AND DEQUE ARE NOT THE SAME!\033[0m " << this->_vector.at(i) << " & " << this->_deque.at(i) << std::endl;
			passed = false;
		}
	}
	if (passed == true)
		std::cout << "\033[1;32mOK\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mKO\033[0m" << std::endl;
}

int PmergeMe::getSize() {
	return (this->_vector.size());
}
