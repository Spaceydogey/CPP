NAME = ex03
 
SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
	   
OBJ = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror $(CPPFLAGS) $(FFLAGS) -g
CPPFLAGS = -std=c++98
FFLAGS = -fsanitize=address

CC = c++

RM = rm -f

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		
.cpp.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean 
		$(RM) $(NAME)

re :	fclean $(NAME) 

.PHONY: all clean fclean re