# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 12:26:37 by dboyer            #+#    #+#              #
#    Updated: 2021/01/16 10:43:25 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cast

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -O3 -std=c++98

SRCS = ./A.cpp ./B.cpp ./C.cpp ./Base.cpp
MAIN = ./main.cpp

OBJS = $(SRCS:.cpp=.o)
MAIN_OBJS = $(MAIN:.cpp=.o)

HEADERS = ./A.hpp ./B.hpp ./C.hpp ./Base.hpp

RM = rm -rf 

%.o: %.cpp ${HEADERS}
	$(CXX) $(CXXFLAGS) -c $< -o $@

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
