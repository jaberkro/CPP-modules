#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <inttypes.h>
# include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &src);
		Serializer& operator=(const Serializer &src);
		~Serializer();

	uintptr_t	serialize(Data* ptr);		
	Data*		deserialize(uintptr_t raw);
};

#endif
