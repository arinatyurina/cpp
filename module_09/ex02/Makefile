# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 21:08:35 by atyurina          #+#    #+#              #
#    Updated: 2026/03/05 19:21:14 by atyurina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := PmergeMe
SRC := main.cpp PmergeMe.cpp

OBJ := $(SRC:.cpp=.o)

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror  -g

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