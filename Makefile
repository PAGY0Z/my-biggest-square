##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## make it
##

CC 	= 	gcc

NAME =	bsq

SRC	= 	src/bsq_main_file.c \
		src/bsq_map_process.c \
		src/bsq_ranges.c \
		src/default_func1.c \
		src/default_func2.c \
		src/default_func3.c \
		src/bsq_struct_update.c \
		src/bsq_map_checker.c

INCLUDE = 	./

CFLAG 	= 	-W -Wall -Wextra -Werror

TEST	=	--coverage -lcriterion

all:
	gcc -o $(NAME) $(SRC) $(CFLAG)

clean:
	rm -f a.out
	rm -f $(NAME) $(BNAME)

fclean: clean

re: fclean all
