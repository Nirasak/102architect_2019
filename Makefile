##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c	\
		src/print_descr.c	\
		src/archi.c	\
		src/check_error.c	\
		src/init_ope.c	\
		src/print.c	\
		src/calcul.c	\
		src/free.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	102architect

CFLAGS	=	-W -Wall -I include/

LDFLAGS	=	-lm

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f *~
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
