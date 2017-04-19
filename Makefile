NAME = baalbane.filler

SRC_PATH = ./src/

SRC_NAME =	main.c algo.c \
			tool.c getscore.c \
			init.c get_next_line.c \
			lsttool.c printtool.c

CC = gcc
FLAGS = -Wall -Werror -Wextra
DEL = rm -rf

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	$(DEL) ./include/filler.h.gch

fclean: clean
	$(DEL) $(NAME)

re: fclean all

.PHONY: all clean fclean re
