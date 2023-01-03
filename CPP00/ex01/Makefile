# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaberkro <jaberkro@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/05 16:01:24 by jaberkro      #+#    #+#                  #
#    Updated: 2023/01/03 14:34:48 by jaberkro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -std=c++98 #-pedantic
SRC = PhoneBook.cpp Contact.cpp main.cpp
INC = PhoneBook.hpp Contact.hpp

NAME = F•R•I•E•N•D•S

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME) 

clean:

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
