# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 21:31:01 by benanredzhe       #+#    #+#              #
#    Updated: 2024/09/25 10:02:51 by beredzhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fixed

SRC		=	$(shell find -name '*.cpp')
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