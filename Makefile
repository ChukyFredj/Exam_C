##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file.
##

SRC	=	./main.c \
		./src/exo1.c \
		./src/exo2.c \
		./src/menu.c \
		./src/main_Article.c

OBJ	=	$(notdir $(SRC:.c=.o))

NAME	=	Exam

all:	$(NAME)

$(NAME):
	gcc -c $(SRC)
	gcc -o $(NAME) $(OBJ) -lm

clean:
	rm -f *.o
	rm -f *# *~ ./*/*# ./*/*~ ./*/*/*# ./*/*/*~ vgcore*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

valgrind:	clean
	gcc -g3 -o $(NAME) $(SRC)

update:
	mmakefile Exam -c

prepush: fclean
	git add .
	git status

full: update
	make re

pull:
	git pull origin master

tree: prepush
	tree -a -I .git

debug: clean
	gcc -g3 -o $(NAME) $(SRC) -Wall -Wextra -pedantic

push: prepush
	git commit -m "push auto"
	git push origin master
