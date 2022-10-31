# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaberkro <jaberkro@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/25 19:58:38 by jaberkro      #+#    #+#                  #
#    Updated: 2022/10/31 17:09:39 by jaberkro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp zombieHorde.cpp
INC = Zombie.hpp
NAME = zombieHorde

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) -I $(INC) $(SRC) -o $(NAME)
	
clean:

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re