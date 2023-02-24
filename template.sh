#! /bin/bash

name=$1;

if ! test -f Makefile; then
	touch Makefile;

	echo "CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = \$(wildcard *.cpp)
OBJ = \$(SRC:.cpp=.o)
NAME = #fill in

all: \$(NAME)

\$(NAME): \$(OBJ)
	\$(CXX) \$(CXXFLAGS) \$(OBJ) -o \$(NAME)

%.o: %.cpp
	\$(CXX) \$(CXXFLAGS) -c \$^ -o \$@

clean:
	rm -rf \$(OBJ)

fclean: clean
	rm -rf \$(NAME)

re: fclean all

debug: CXXFLAGS = -fsanitize=address 
debug: re

.PHONY: all, clean, fclean, re, debug" > Makefile;
fi

if ! test -f main.cpp; then
	touch main.cpp;

	echo "int	main(void)
{

	return (0);	
}" > main.cpp;
fi

for var in $@; do
	if ! test -f $var.cpp; then
		touch $var.cpp;

		echo "#include \"$var.hpp\"
#include <iostream>

$var::$var(void)
{
	std::cout << \"Default constructor called on $var\" << std::endl;
}

$var::$var(const $var &src)
{
	std::cout << \"Copy constructor called on $var\" << std::endl;
	*this = src;
}

$var& $var::operator=(const $var &src)
{
	std::cout << \"Copy assignment operator called on $var\" << std::endl;
	//copy variables
	return (*this);
}

$var::~$var(void)
{
	std::cout << \"Destructor called on $var\" << std::endl;
}" > $var.cpp;
fi

if ! test -f $var.hpp; then
	touch $var.hpp;

	bigvar=$(echo $var | tr 'a-z' 'A-Z')
	echo "#ifndef ${bigvar}_HPP
# define ${bigvar}_HPP

class $var
{
	public:
		$var();
		$var(const $var &src);
		$var& operator=(const $var &src);
		~$var();

	private:

};

#endif" > $var.hpp;
fi

done
