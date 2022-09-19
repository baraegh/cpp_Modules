NAME = megaphone

SRC = megaphone.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++98

${NAME} : ${SRC}
		g++ ${CFLAGS} ${SRC} -o ${NAME}

all : ${NAME}

clean :
		rm -r ${NAME}

fclean : clean
		rm -r ${NAME}

re : fclean all