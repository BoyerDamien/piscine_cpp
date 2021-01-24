# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 13:27:57 by dboyer            #+#    #+#              #
#    Updated: 2021/01/24 13:27:59 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -O3 -std=c++98

MAIN = ./main.cpp

MAIN_OBJS = $(MAIN:.cpp=.o)

HEADERS = ./Array.hpp

RM = rm -rf 

%.o: %.cpp ${HEADERS}
	$(CXX) $(CXXFLAGS) -c $< -o $@

all     :	$(NAME)

$(NAME) :	$(MAIN_OBJS)
	${CXX} ${CXXFLAGS} -o ${NAME} ${MAIN_OBJS}

clean   :
	$(RM) $(MAIN_OBJS)

fclean  : clean
	$(RM) $(NAME)

re      :	fclean all

run: all
	./${NAME} | cat -e
