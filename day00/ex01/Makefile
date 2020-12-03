# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 12:26:37 by dboyer            #+#    #+#              #
#    Updated: 2020/12/03 15:56:12 by dess             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = annuaire

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -O3 -std=c++98

SRCS = ./Contact.class.cpp ./Annuaire.class.cpp
MAIN = ./main.cpp

OBJS = $(SRCS:.cpp=.o)
MAIN_OBJS = $(MAIN:.cpp=.o)

RM = rm -rf 

all     :	$(NAME)

$(NAME) :	$(OBJS) $(MAIN_OBJS)
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS} ${MAIN_OBJS}

clean   :
	$(RM) $(OBJS)
	$(RM) $(MAIN_OBJS)

fclean  : clean
	$(RM) $(NAME)

re      :	fclean all

run: all
	./${NAME} | cat -e
