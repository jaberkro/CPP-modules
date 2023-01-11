# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaberkro <jaberkro@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/25 19:58:38 by jaberkro      #+#    #+#                  #
#    Updated: 2023/01/11 15:06:32 by jaberkro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -pedantic -std=c++98 -fsanitize=address
SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
INC = Zombie.hpp
NAME = zombie

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) -I $(INC) $(SRC) -o $(NAME)
	
clean:

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re