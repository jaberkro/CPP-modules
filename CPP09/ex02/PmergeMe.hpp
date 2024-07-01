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

		void	prepareContainers(int argc, char **argv);
		void	sortVector(size_t pairSize);
		void	setSortedFalse(void);
		void	sortDeque(size_t pairSize);
		void	show();
		int		getSize();
		void	test();

	private:
		PmergeMe(const PmergeMe &src);
		PmergeMe& operator=(const PmergeMe &src);

		void	parseArgument(std::string s);
		void	storeInput(long input);
		void	createJacobsthal(void);

		template<typename T>
		void	swapPairs(T &t, size_t pairSize);

		template <typename T>
		void	movePair(T &t, size_t from, size_t to, size_t range);
		
		template<typename T>
		void	sortSmallestInPairs(T &t, size_t pairSize);

		template<typename T>
		size_t	findCorrectLocation(T &t, size_t toSortIndex, size_t pairSize, size_t min, size_t max);
		size_t	findMiddle(size_t minIndex, size_t maxIndex);

		template<typename T>
		void	placeStraggler(T &t, size_t pairSize);

		std::deque<int>		_deque;
		std::vector<int>	_vector;
		std::vector<bool>	_sorted;
		std::vector<size_t>	_jacobsthalVector;
};

#endif
