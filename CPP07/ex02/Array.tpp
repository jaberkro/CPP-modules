#ifndef ARRAY_TPP
# define ARRAY_TPP
# include "Array.hpp"

template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return ("Exception: Index out of bounds");
}

template <typename T>
Array<T>::Array(void)
{
	this->_t = new T[0];
	this->_len = 0;
	std::cout << "Default constructor called on Array" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_t = new T[n];
	for (unsigned int i = 0; i < n; i++)
	{
		this->_t[i] = 0;
	}
	this->_len = n;
	std::cout << "Parametric constructor called on Array" << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T> &src)
{
	*this = src;
	std::cout << "Copy constructor called on Array" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &src)
{
	this->_t = new T[src._len];
	for (unsigned int i = 0; i < src.size(); i++)
	{
		this->_t[i] = src._t[i];
	}
	this->_len = src._len;
	std::cout << "Copy assignment operator called on Array" << std::endl;
	return (*this);
}

template <typename T>
T& Array<T>::operator[](int n)
{
	if (n < 0 || n >= this->_len)
		throw Array::IndexOutOfBoundsException();
	// std::cout << "Subscript operator called on Array" << std::endl;
	return ((this->_t)[n]);
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->_t;
	std::cout << "Default destructor called on Array" << std::endl;
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_len);
}

#endif
