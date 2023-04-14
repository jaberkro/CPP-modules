#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &src);
		Span& operator=(const Span &src);
		~Span();

		void	addNumber(int n);
		int		shortestSpan(void);
		int		longestSpan(void);

		void 	addManySameNumbers(int amount, int value);
		void	addIncrementingNumbers(int start, int end);

		std::vector<int>	_vector;
		unsigned int		_index;

		class	IndexOutOfRangeException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	TooSmallException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:

		Span();
};

#endif
