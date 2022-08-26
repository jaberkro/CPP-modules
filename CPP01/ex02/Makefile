# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaberkro <jaberkro@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/26 15:43:55 by jaberkro      #+#    #+#                  #
#    Updated: 2022/08/26 15:44:28 by jaberkro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
NAME = brain

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)
	
clean:

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
