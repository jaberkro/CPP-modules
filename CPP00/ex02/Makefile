# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaberkro <jaberkro@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/31 13:17:51 by jaberkro      #+#    #+#                  #
#    Updated: 2022/10/31 14:58:07 by jaberkro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Account.cpp tests.cpp
INC = Account.hpp
NAME = dreamjob

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) -I $(INC) $(SRC) -o $(NAME)
	
clean:

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
