NAME = convert
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++2a
SRC = main.cpp ScalarConverter.cpp
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