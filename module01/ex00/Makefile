# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#              #
#    Updated: 2023/10/25 19:14:28 by aotsala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brainz
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
						$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
						$(CC) $(FLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJ)

fclean:	clean
		@$(RM) $(NAME)

re:		fclean all

PHONY: all fclean clean re