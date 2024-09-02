# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 20:43:46 by benanredzhe       #+#    #+#              #
#    Updated: 2024/09/02 20:56:57 by benanredzhe      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= phonebook

SRC_DIR = src
SRCS 	= $(wildcard *.cpp)

SRC 	= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ		= $(patsubst %.cpp, %.o, $(SRCS)

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

.PHONY all clean fclean re