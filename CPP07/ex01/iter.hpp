#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename V>
void	iter(T t, unsigned int u, V v)
{
	for (unsigned int i = 0; i < u; i++)
	{
		v(t[i]);
	}
}

#endif
