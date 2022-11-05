# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 11:37:18 by obelkhad          #+#    #+#              #
#    Updated: 2022/11/05 12:03:14 by obelkhad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = container
CPPFLAG = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	@c++ $(CPPFLAG) $(OBJ) -o $(NAME)
%.o:%.cpp ft_vector/ft_vector.hpp
	@C++ $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf  $(OBJ)

fclean: clean 
	@rm -f $(NAME)

re: fclean all

