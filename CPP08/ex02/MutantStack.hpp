#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &src);
		MutantStack& operator=(const MutantStack &src);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		iterator			begin(void);
		iterator			end(void);
		reverse_iterator	rbegin(void);
		reverse_iterator	rend(void);
};

# include "MutantStack.tpp"

#endif
