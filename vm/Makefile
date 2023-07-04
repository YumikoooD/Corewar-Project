##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SOURCE =	src/

FIGHTER_INIT	=	src/vm_init/fighter_init/

FIGHTER_INIT_ARGS	=	src/vm_init/args/

DESTROY	=	src/destroy/

VM_INIT	=	src/vm_init/

INSTRUCTION	=	src/instruction/

UTILS	=	src/utils/

FIGHTER_LOOP	=	src/fighter_loop/

SRC =	$(FIGHTER_INIT)asm_fighter.c			\
		$(FIGHTER_INIT)getline_file.c			\
		$(FIGHTER_INIT)get_cor_file.c			\
		$(FIGHTER_INIT)reverse.c				\
		$(FIGHTER_INIT)add_fighter.c			\
		$(FIGHTER_INIT)file_manager.c			\
		$(FIGHTER_INIT)flags_manager.c			\
		$(FIGHTER_INIT)init_data.c				\
		$(FIGHTER_LOOP)sorting.c				\
		$(FIGHTER_LOOP)show_win.c				\
		$(FIGHTER_LOOP)find_dead_fighter.c		\
		$(FIGHTER_LOOP)fighter_fight.c			\
		$(FIGHTER_LOOP)detect_error.c			\
		$(FIGHTER_INIT)get_header.c				\
		$(FIGHTER_INIT_ARGS)dump.c 				\
		$(FIGHTER_INIT_ARGS)load_prog_adress.c 	\
		$(FIGHTER_INIT_ARGS)load_prog_nb.c 		\
		$(FIGHTER_INIT_ARGS)show_help.c			\
		$(VM_INIT)vm_init.c						\
		$(VM_INIT)place_fighter.c				\
		$(VM_INIT)init_arena.c					\
		$(VM_INIT)error_input.c					\
		$(UTILS)my_memset.c						\
		$(UTILS)adress.c						\
		$(UTILS)pc.c							\
		$(UTILS)get_args.c						\
		$(UTILS)maths.c							\
		$(UTILS)type_args.c						\
		$(UTILS)write_nbytes.c					\
		$(UTILS)cpy_fighter.c					\
		$(DESTROY)destroy.c						\
		$(INSTRUCTION)cmd_live.c				\
		$(INSTRUCTION)cmd_add.c					\
		$(INSTRUCTION)cmd_aff.c					\
		$(INSTRUCTION)cmd_and.c					\
		$(INSTRUCTION)cmd_sub.c					\
		$(INSTRUCTION)cmd_zjmp.c				\
		$(INSTRUCTION)cmd_or.c					\
		$(INSTRUCTION)cmd_xor.c					\
		$(INSTRUCTION)cmd_ld.c					\
		$(INSTRUCTION)cmd_lld.c					\
		$(INSTRUCTION)cmd_ldi.c					\
		$(INSTRUCTION)cmd_lldi.c				\
		$(INSTRUCTION)cmd_st.c					\
		$(INSTRUCTION)cmd_sti.c					\
		$(INSTRUCTION)cmd_detector.c			\
		$(INSTRUCTION)cmd_fork.c				\
		$(INSTRUCTION)cmd_lfork.c				\
		$(SOURCE)main.c							\

OBJ	=	$(SRC:.c=.o)

NAME	=	corewar

CPPFLAGS = -iquote./include/

CFLAGS	= -Wall -Wextra -g3

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
