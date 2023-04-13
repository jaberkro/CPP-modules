#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		Array& operator=(const Array &src);
		T& operator[](int n);
		~Array();

		unsigned int size(void) const;

		class	IndexOutOfBoundsException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		T*	_t;
		int	_len;
};

# include "Array.tpp"

#endif
