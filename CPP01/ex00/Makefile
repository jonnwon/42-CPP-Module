NAME		=	BraiiiiiiinnnzzzZ

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp\
				Zombie.cpp\
				newZombie.cpp\
				randomChump.cpp\

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
