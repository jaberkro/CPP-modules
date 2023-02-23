# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaberkro <jaberkro@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/18 12:19:09 by jaberkro      #+#    #+#                  #
#    Updated: 2023/02/23 10:42:34 by jaberkro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = main.cpp ClapTrap.cpp
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))
NAME = claptrap

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug: CXXFLAGS = -fsanitize=address
debug: fclean all

.PHONY: all, clean, fclean, re, debug
