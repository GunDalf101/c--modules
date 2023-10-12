CC = c++
CFLAGS = -Wall -Wextra -Wshadow -Wno-shadow -Werror -std=c++98
RM = rm -rf
NAME = DiamondTrap

SRCS = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME) ClapTrap.hpp

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re run