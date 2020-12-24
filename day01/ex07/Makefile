# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 12:26:37 by dboyer            #+#    #+#              #
#    Updated: 2020/12/24 12:49:50 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -O3 -std=c++98

MAIN = ./main.cpp

MAIN_OBJS = $(MAIN:.cpp=.o)

RM = rm -rf 

all     :	$(NAME)

$(NAME) :	$(MAIN_OBJS)
	${CXX} ${CFLAGS} -o ${NAME} ${MAIN_OBJS}

clean   :
	$(RM) $(MAIN_OBJS)

fclean  : clean
	$(RM) $(NAME)

re      :	fclean all

run: all
	cp Makefile Makefile2 && ./${NAME} Makefile2 CXX CDD && cat Makefile2 -e
