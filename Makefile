##
## EPITECH PROJECT, 2023
## CSFML-Menus-Scenes
## File description:
## Makefile
##

NAME			=			game

SRC_MAIN		=			src/main.c
SRC				=			$(addprefix src/,	\
								destroy.c		\
								display.c		\
								events.c		\
								game.c			\
								init.c			\
							)

OBJ_MAIN		=			$(SRC_MAIN:.c=.o)
OBJ				=			$(SRC:.c=.o)

CC 				=			gcc
RM 				=			rm -rf
CFLAGS 			+= 			-Iinclude -Wall -Wextra -Werror
LDFLAGS			+=			-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ) $(OBJ_MAIN)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
