# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaberkro <jaberkro@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/18 12:19:09 by jaberkro      #+#    #+#                  #
#    Updated: 2023/02/23 10:31:59 by jaberkro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC =  main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ = $(SRC:.cpp=.o)
NAME = scavtrap

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	rm $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug: CXXFLAGS = -fsanitize=address
debug: fclean all

.PHONY: all, clean, fclean, re, debug
