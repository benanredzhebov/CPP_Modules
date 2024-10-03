# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 08:54:27 by beredzhe          #+#    #+#              #
#    Updated: 2024/10/03 16:50:13 by benanredzhe      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	claptrap

SRC		=	$(shell find . -name '*.cpp')
OBJ		=	$(SRC:.cpp=.o)

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp -o $(NAME)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re