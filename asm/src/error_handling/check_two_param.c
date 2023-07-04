/*
** EPITECH PROJECT, 2023
** asm corewar
** File description:
** error handling check 2 param
*/

#include "my.h"
#include "asm.h"

int check_ld(char **cmd)
{
    if (my_arrlen(cmd) != 3) {
        my_puterr("Wrong nb of parameters ((l)ld)\n");
        return 84;
    }
    if (is_a_register(cmd[2]) == -1) {
        my_puterr("Invalid register ((l)ld)\n");
        return 84;
    }
    return 0;
}

int check_st(char **cmd)
{
    if (my_arrlen(cmd) != 3) {
        my_puterr("Wrong nb of parameters (st)\n");
        return 84;
    }
    if (is_a_register(cmd[1]) == -1) {
        my_puterr("Invalid register (st)\n");
        return 84;
    }
    if (is_a_register(cmd[2]) == -1 && my_atoi(cmd[2]) == LEN_ERROR &&
        cmd[2][0] != '%' && cmd[2][0] != ':') {
        my_puterr("Invalid argument (st)\n");
        return 84;
    }
    return 0;
}
