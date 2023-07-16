# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 19:17:21 by jonchoi           #+#    #+#              #
#    Updated: 2023/07/15 19:18:22 by jonchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	phonebook

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp

OBJS_DIR	=	objs

OBJS	=	$(SRC:%.cpp=$(OBJS_DIR)/%.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


$(OBJS_DIR)/%.o	:	%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

clean	:
	rm -rf $(OBJS_DIR)

fclean	:
	make clean
	rm -rf $(NAME)

re		:
	make fclean
	make all

.PHONY	:	all clean fclean re
