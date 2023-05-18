#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <array>
# include <vector>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe& operator=(const PmergeMe &src);
		~PmergeMe();

		// sort(std::array<int> a);
		// sort(std::vector<int> v);
};

#endif
