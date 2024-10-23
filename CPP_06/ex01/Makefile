# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:14:14 by beredzhe          #+#    #+#              #
#    Updated: 2024/10/23 14:49:25 by beredzhe         ###   ########.fr        #
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

re: fcleam

.PHONY: all clean fclean re