#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <iostream>
# include <algorithm>

template<typename T>
void	easyfind(T t, int n)
{
	bool	found = 0;

	for (unsigned int i = 0; i < t.size(); i++)
	{
		if (t[i] == n)
			found = 1;
	}
	if (found == 0)
		throw std::exception();
}

#endif
