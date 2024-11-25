CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
NAME = RPN

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug: CXXFLAGS = -fsanitize=address 
debug: re

.PHONY: all, clean, fclean, re, debug
