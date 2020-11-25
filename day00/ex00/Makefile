# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 12:29:01 by dboyer            #+#    #+#              #
#    Updated: 2020/11/25 12:29:03 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = clang++

CFLAGS = -Wall -Wextra -Werror -O3 -std=c++98

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf 

all     :	$(NAME)

$(NAME) :	$(OBJS)
	${CXX} ${CFLAGS} -o ${NAME} ${OBJS}

clean   :
	$(RM) $(OBJS)

fclean  : clean
	$(RM) $(NAME)

re      :	fclean all

run: all
	./${NAME}
	./${NAME} "ceci est un test"
	./${NAME} ceci est un second test
