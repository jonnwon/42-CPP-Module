# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonchoi <jonchoi@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 21:17:28 by jonchoi           #+#    #+#              #
#    Updated: 2023/07/11 21:17:34 by jonchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	megaphone.cpp

OBJS_DIR	=	objs

OBJS		=	$(SRC:%.cpp=$(OBJS_DIR)/%.o)

all		:	$(NAME)

$(OBJS_DIR)/%.o	:	%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo compiled!

clean	:
	@rm -rf $(OBJS_DIR)

fclean	:
	@make clean
	@rm -rf $(NAME)

re		:
	@make fclean
	@make all

.PHONY	:	all clean fclean re
