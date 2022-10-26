NAME = I_dont_want_to_set_the_the_world_on_fire

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp Wrongcat.cpp Brain.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(SRC)
	g++ $(FLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all