NAME = unnecessary_violence

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(SRC)
	g++ $(FLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all