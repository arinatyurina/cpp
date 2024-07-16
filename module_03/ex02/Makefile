# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 15:12:01 by atyurina          #+#    #+#              #
#    Updated: 2024/07/16 15:46:16 by atyurina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := clap_trap
SRC := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJ := $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	chmod +x $(NAME)
	
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re