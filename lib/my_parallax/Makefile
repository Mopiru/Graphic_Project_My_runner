##
## EPITECH PROJECT, 2017
## my_printf
## File description:
## Makefile
##

cc 	=	gcc

CFLAGS	=	-W -Wall -Wextra -lm -I ../../include/ -l csfml-window -l csfml-system

LIB	=	-L./lib -l

SRC	=	src/chain_parallax.c	\
		src/my_parallax.c	\
		src/bg/desert_one.c	\
		src/bg/desert_two.c	\
		src/bg/candy_one.c	\
		src/bg/candy_two.c	\
		src/bg/candy_tree.c	\
		src/bg/candy_four.c	\
		src/bg/candy_five.c	\
		src/bg/candy_six.c	\
		src/bg/candy_seven.c	\
		src/bg/candy_height.c	\
		src/bg/forest_one.c	\
		src/bg/forest_two.c	\
		src/bg/forest_three.c	\
		src/bg/forest_four.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	../libmy_parallax.a

all:		create	clean

create:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	re -f $(NAME)

re:	fclean	all
