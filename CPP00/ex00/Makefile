# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonchoi <jonchoi@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 02:40:30 by jonchoi           #+#    #+#              #
#    Updated: 2023/06/13 02:54:45 by jonchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	megaphone.cpp

OBJS	=	$(SRC:%.cpp=%.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean	:
	@rm -rf $(OBJS)

fclean	:
	@make clean
	@rm -rf $(NAME)

re		:
	@make fclean
	@make all

.PHONY	:	all clean fclean re
