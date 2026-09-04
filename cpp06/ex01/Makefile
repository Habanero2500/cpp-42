# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/18 17:17:29 by jmetayer          #+#    #+#              #
#    Updated: 2026/08/29 16:28:34 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scalar
SRCS = main.cpp ScalarConverter.cpp

CC = c++ 
FLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME)	: $(OBJS)
	@$(CC) $(FLAGS) $^ -o $(NAME)
	@echo '$(NAME) compiled!'

fclean : clean
	@$(RM) $(NAME)

clean :
	@$(RM) $(OBJS)

re			: fclean all

.PHONY : all clean fclean re