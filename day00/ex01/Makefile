NAME = annuaire

CXX = clang++

CFLAGS = -Wall -Wextra -Werror -O3 -std=c++98

SRCS = ./Contact.class.cpp ./Annuaire.class.cpp
MAIN = ./main.cpp

OBJS = $(SRCS:.cpp=.o)
MAIN_OBJS = $(MAIN:.cpp=.o)

RM = rm -rf 

all     :	$(NAME)

$(NAME) :	$(OBJS) $(MAIN_OBJS)
	${CXX} ${CFLAGS} -o ${NAME} ${OBJS} ${MAIN_OBJS}

clean   :
	$(RM) $(OBJS)
	$(RM) $(MAIN_OBJS)

fclean  : clean
	$(RM) $(NAME)

re      :	fclean all

run: all
	./${NAME} | cat -e
