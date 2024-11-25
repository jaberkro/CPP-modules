CXXFLAGS = -Wall -Wextra -Werror -std=c++11

SRC = PmergeMe.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@c++ $(CXXFLAGS) -c $^ -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

debug: CXXFLAGS = -fsanitize=address 
debug: re

.PHONY: all, clean, fclean, re, debug
