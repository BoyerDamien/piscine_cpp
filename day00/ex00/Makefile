# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 12:29:01 by dboyer            #+#    #+#              #
#    Updated: 2020/12/03 15:56:26 by dess             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -O3 -std=c++98

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf 

all     :	$(NAME)

$(NAME) :	$(OBJS)
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

clean   :
	$(RM) $(OBJS)

fclean  : clean
	$(RM) $(NAME)

re      :	fclean all

run: all
	./${NAME}
	./${NAME} "shhhhh... I think the students are asleep..."
	./${NAME} Damnit " ! " "Sorry students, I thought this thing was off."
