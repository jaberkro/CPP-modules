#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <deque>
# include <vector>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		class	NotAPositiveIntegerException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	DuplicateInputException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	NotEnoughArgumentsException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		int		fillContainers(int argc, char **argv);
		void	start();
		void	sortVector(size_t pairSize);
		void	sortDeque(size_t pairSize);
		void	finish();
		void	show();
		void	test();
		int		getSize();

	private:
		PmergeMe(const PmergeMe &src);
		PmergeMe& operator=(const PmergeMe &src);

		template <typename T>
		void	show(T &t);

		template<typename T>
		void	swapPairs(T &t, size_t pairSize);

		void	createJacobsthal(void);

		template <typename T>
		void	movePair(T &t, size_t from, size_t to, size_t range);
		
		template<typename T>
		void	sortSmallestInPairs(T &t, size_t pairSize);

		template<typename T>
		size_t	findCorrectLocation(T &t, size_t toSortIndex, size_t pairSize, size_t min, size_t max);
		size_t	findMiddle(size_t minIndex, size_t maxIndex);

		std::deque<int>		_deque;
		std::vector<int>	_vector;
		std::vector<bool>	_sorted;
		std::vector<size_t>	_jacobsthalVector;
};

#endif
