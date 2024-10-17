NAME	=	phonebook
COMP	=	g++ -std=c++98
FLAGS	=	-Wall -Werror -Wextra
SRC		=	PhoneBook.cpp main.cpp
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)
	
$(NAME): $(OBJ)
	$(COMP) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@$(COMP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.phony: all clean fclean re