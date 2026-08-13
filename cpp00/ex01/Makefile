# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/23 14:04:09 by jmetayer          #+#    #+#              #
#    Updated: 2026/06/26 14:49:25 by jmetayer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
SRCS = PhoneBook.cpp main.cpp utils.cpp Contact.cpp

CC = clang++ 
FLAGS = -Wall -Werror -Wextra -g -std=c++98
DIR = obj/

RM = rm -rf
OBJS = $(addprefix $(DIR),$(SRCS:.cpp=.o))
DEPS = $(addprefix $(DIR),$(SRCS:.cpp=.d))

$(DIR)%.o: %.cpp | $(DIR)
	@$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo '$(NAME) compiled!'

$(DIR) :
	mkdir -p $(DIR)
	

fclean : clean
	@$(RM) $(NAME)

clean :
	@$(RM) $(DIR)

re			: fclean all

.PHONY : all clean fclean re