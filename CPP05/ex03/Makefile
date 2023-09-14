NAME		=	Intern

CXX			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp\
				Bureaucrat.cpp\
				AForm.cpp\
				ShrubberyCreationForm.cpp\
				RobotomyRequestForm.cpp\
				PresidentialPardonForm.cpp\
				Intern.cpp\

OBJS_DIR	=	objs

OBJS	=	$(SRC:%.cpp=$(OBJS_DIR)/%.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)


$(OBJS_DIR)/%.o	:	%.cpp
	mkdir -p $(@D)
	$(CXX) $(CFLAGS) -c $^ -o $@

clean	:
	rm -rf $(OBJS_DIR)

fclean	:
	make clean
	rm -rf $(NAME)

re		:
	make fclean
	make all

.PHONY	:	all clean fclean re
