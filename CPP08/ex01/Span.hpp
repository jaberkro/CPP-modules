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

		void					addNumber(int n);
		int						shortestSpan(void);
		int						longestSpan(void);
		const std::vector<int> 	&getVector(void) const;

		void	addIncrementingNumbers(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end, int startNumber);

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
		std::vector<int>	_vector;

		Span();
};

#endif
