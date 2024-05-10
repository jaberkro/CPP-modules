#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP
# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void)
{
	std::cout << "Default constructor called on MutantStack" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src)
{
	std::cout << "Copy constructor called on MutantStack" << std::endl;
	*this = src;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &src)
{
	std::cout << "Copy assignment operator called on MutantStack" << std::endl;
	std::stack<int>::operator=(src);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << "Destructor called on MutantStack" << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
}

#endif
