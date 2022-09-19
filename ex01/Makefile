NAME = phonebook

SRC = main.cpp PhoneBook.cpp Contact.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++98

${NAME} : ${SRC}
		g++ ${CFLAGS} ${SRC} -o ${NAME}

all : ${NAME}

clean :
		rm -fr ${NAME}

fclean : clean
		rm -fr ${NAME}

re : fclean all