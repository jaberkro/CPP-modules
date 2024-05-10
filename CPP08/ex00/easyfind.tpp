#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <iostream>
# include <algorithm>
# include <iterator>

template<typename T>
typename T::iterator	easyfind(T &t, int n)
{
	typename T::iterator result = std::find(t.begin(), t.end(), n);
	if (result == t.end())
		throw (std::runtime_error("Int not found"));
	return (result);
}

#endif
