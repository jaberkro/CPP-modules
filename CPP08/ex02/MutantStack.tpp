#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP
# include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void)
{
	std::cout << "Default constructor called on MutantStack" << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &src)
{
	std::cout << "Copy constructor called on MutantStack" << std::endl;
	*this = src;
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack &src)
{
	std::cout << "Copy assignment operator called on MutantStack" << std::endl;
	(void)src;
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void)
{
	std::cout << "Destructor called on MutantStack" << std::endl;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin(void)
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end(void)
{
	return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rbegin(void)
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rend(void)
{
	return (this->c.end());
}

#endif
