/*
** EPITECH PROJECT, 2023
** error handling one param
** File description:
** asm corewar
*/

#include "my.h"
#include "op.h"
#include "asm.h"

int check_live(char **cmd)
{
    if (my_arrlen(cmd) != 2) {
        my_puterr("Wrong nb of parameters (live)\n");
        return 84;
    }
    return 0;
}

int check_zjmp(char **cmd)
{
    if (my_arrlen(cmd) != 2) {
        my_puterr("Wrong nb of parameters (zjmp)\n");
        return 84;
    }
    if (my_atoi(cmd[1]) == LEN_ERROR && cmd[1][0] != '%' &&
        cmd[2][0] != ':') {
        my_puterr("Invalid index value (zjmp)");
        return 84;
    }
    return 0;
}

int check_aff(char **cmd)
{
    if (my_arrlen(cmd) != 2) {
        my_puterr("Wrong nb of parameters (aff)\n");
        return 84;
    }
    if (is_a_register(cmd[1]) == -1) {
        my_puterr("Invalid register (aff)\n");
        return 84;
    }
    return 0;
}

int check_fork(char **cmd)
{
    if (my_arrlen(cmd) != 2) {
        my_puterr("Wrong nb of parameters ((l)fork)\n");
        return 84;
    }
    if (my_atoi(cmd[1]) == LEN_ERROR && cmd[1][0] != '%' &&
        cmd[1][0] != ':') {
        my_puterr("Invalid index value (zjmp)");
        return 84;
    }
    return 0;
}
