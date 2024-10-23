# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:14:14 by beredzhe          #+#    #+#              #
#    Updated: 2024/10/23 22:03:44 by benanredzhe      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	serializer

SRC		=	$(shell find . -name '*.cpp')
OBJ		=	$(SRC:.cpp=.o)

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re