# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 17:02:49 by beredzhe          #+#    #+#              #
#    Updated: 2024/10/09 11:40:48 by beredzhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	animal

SRC		=	$(shell find src -name "*.cpp")
OBJ		=	$(SRC:.cpp=.o)

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re