##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

all:
	make -C asm/
	make -C vm/

clean :
	make -C asm/ clean
	make -C vm/ clean

fclean: clean
	make -C asm/ fclean
	make -C vm/ fclean

re:     fclean all

.PHONY: all clean fclean re
