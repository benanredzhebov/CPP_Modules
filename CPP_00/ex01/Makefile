# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 20:43:46 by benanredzhe       #+#    #+#              #
#    Updated: 2024/09/08 11:08:09 by beredzhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= phonebook

SRC_DIR = src
SRCS 	= $(shell find $(SRC_DIR) -name '*.cpp')

SRC 	= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ		= $(patsubst %.cpp, %.o, $(notdir $(SRCS)))

CC 		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re