##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile day13
##

CC	=	gcc

CFLAGS	=	-g -W -Wall -Wextra -I include/ -l csfml-graphics

CFLAG	=	-l csfml-window -l csfml-system

LIB	=	-L./lib -lmy_parallax

SRC	=	src/main.c	\
		src/get_map.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my_parallax/
	$(CC) $(OBJ) $(CFLAGS) $(CFLAG) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
