# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 11:37:18 by obelkhad          #+#    #+#              #
#    Updated: 2022/12/21 14:28:59 by obelkhad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = container
CPPFLAG = -Wall -Wextra -Werror -std=c++98 -g
AR = ar rcs
LIBR = lib/objects.a

VECTORSRC = test/vector/test0.cpp test/vector/test1.cpp test/vector/test2.cpp\
			test/vector/test3.cpp test/vector/test4.cpp test/vector/test5.cpp\
			test/vector/test6.cpp test/vector/test7.cpp test/vector/test8.cpp\
			test/vector/test9.cpp test/vector/test10.cpp test/vector/test11.cpp\
			test/vector/test12.cpp test/vector/test13.cpp test/vector/test14.cpp\
			test/vector/test15.cpp test/vector/test16.cpp test/vector/test17.cpp

STACKSRC = 	test/stack/test0.cpp test/stack/test1.cpp test/stack/test2.cpp\
			test/stack/test3.cpp test/stack/test4.cpp 


MAPSRC = TreeDisplay/display.cpp

VECTOROBJ = $(VECTORSRC:.cpp=.o)
STACKOBJ = $(STACKSRC:.cpp=.o)
MAPOBJ = $(MAPSRC:.cpp=.o)

all: $(NAME)
	c++ main.cpp $(CPPFLAG) $(LIBR) -o $(NAME)

$(NAME): $(VECTOROBJ) $(STACKOBJ) $(MAPOBJ)
	$(AR) $(LIBR) $(VECTOROBJ) $(STACKOBJ) $(MAPOBJ)

%.o:%.cpp Containers/*.hpp test.hpp
	c++ $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(VECTOROBJ) $(STACKOBJ) $(MAPOBJ)
	@rm -rf $(LIBR) 

fclean: clean 
	@rm -f $(NAME)

re: fclean all

