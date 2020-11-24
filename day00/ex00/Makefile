NAME = megaphone

CC = clang++

CFLAGS = -Wall -Wextra -Werror -O3 -std=c++98

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf 

all     :	$(NAME)

$(NAME) :	$(OBJS)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean   :
	$(RM) $(OBJS)

fclean  : clean
	$(RM) $(NAME)

re      :	fclean all

run: all
	./${NAME}
	./${NAME} "ceci est un test"
	./${NAME} ceci est un second test
