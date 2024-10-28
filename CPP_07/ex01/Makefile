# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 21:43:56 by benanredzhe       #+#    #+#              #
#    Updated: 2024/10/28 21:43:59 by benanredzhe      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	iter

SRC		=	$(shell find . -name '*cpp')
OBJ		=	$(SRC:.cpp=.o)

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.cpp:%.o
	$(CC) $(CFLAGS) -c $< -o  $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re