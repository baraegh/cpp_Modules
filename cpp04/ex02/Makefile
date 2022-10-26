NAME = abstract_class

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp Wrongcat.cpp Brain.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(SRC)
	g++ $(FLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all