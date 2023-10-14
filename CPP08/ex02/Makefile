NAME		=	Mutated_abomination

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp\

OBJS_DIR	=	objs

OBJS	=	$(SRC:%.cpp=$(OBJS_DIR)/%.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


$(OBJS_DIR)/%.o	:	%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean	:
	rm -rf $(OBJS_DIR)

fclean	:
	make clean
	rm -rf $(NAME)

re		:
	make fclean
	make all

.PHONY	:	all clean fclean re
