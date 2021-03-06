##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile day13
##

CC	=	gcc

CFLAGS	=	-g -W -Wall -Wextra -I include/ -l csfml-graphics -l csfml-window -l csfml-system

LIB	=	-L./lib -lmy_parallax

SRC	=	src/main.c		\
		src/get_map.c		\
		src/read.c		\
		src/chain.c		\
		src/display_map.c	\
		src/add_block_map.c	\
		src/init_character.c	\
		src/key.c		\
		src/die.c		\
		src/init_window.c	\
		src/init_window_2.c	\
		src/menu.c		\
		src/finish.c		\
		src/my_print_nbr.c	\
		src/re_init.c		\
		src/tools.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my_parallax/
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
