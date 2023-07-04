##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SOURCE =	src/

BODY =		$(SOURCE)body/

ERROR_HANDLING =	$(SOURCE)error_handling/

HEADER =	$(SOURCE)header/

SIZE = 		$(SOURCE)size/

LABEL = 	$(SOURCE)label/

SRC =	$(SOURCE)main.c \
	$(SOURCE)open_files.c \
	$(SOURCE)asm.c \
	$(SOURCE)op.c \
	$(HEADER)header.c \
	$(HEADER)write_header.c \
	$(ERROR_HANDLING)error_handling.c \
	$(ERROR_HANDLING)verif.c \
	$(ERROR_HANDLING)check_one_param.c \
	$(ERROR_HANDLING)check_two_param.c \
	$(ERROR_HANDLING)check_three_param.c \
	$(ERROR_HANDLING)utils.c \
	$(SIZE)size_one_param.c \
	$(SIZE)size_two_param.c \
	$(SIZE)size_three_param.c \
	$(SIZE)utils.c \
	$(LABEL)label.c \
	$(LABEL)label_utils.c \
	$(BODY)command.c    \
	$(BODY)body.c \
	$(BODY)write_params.c \
	$(BODY)write_index.c  \

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

CPPFLAGS = -iquote./include/

CFLAGS	= -Wall -Wextra

LDFLAGS = -L./lib/my

LDLIBS = -lmy

all:	$(NAME)

debug: CFLAGS += -g3

debug: clean $(NAME)

valgrind: debug
	valgrind ./$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

clean :
	make -C lib/my/ clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/my/ fclean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re debug
