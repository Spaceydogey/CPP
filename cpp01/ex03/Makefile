
NAME = violence
 
SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
	   
OBJ = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror $(CPPFLAGS) $(FFLAGS) -g
CPPFLAGS = -std=c++98
FFLAGS = -fsanitize=address

CC = c++

RM = rm -f

$(NAME): $(OBJ)
	$(CC) -g $(CFLAGS) -g $(OBJ) -g -o $(NAME)
		
.c.o:
		$(CC) -g $(CFLAGS) -g -c $< -g -o $(<:.cpp=.o)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean 
		$(RM) $(NAME)

re :	fclean $(NAME) 

.PHONY: all clean fclean re