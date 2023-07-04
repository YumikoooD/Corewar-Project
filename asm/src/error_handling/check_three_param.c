/*
** EPITECH PROJECT, 2023
** asm corewar
** File description:
** check 3 params
*/

#include "asm.h"
#include "my.h"

int check_add_sub(char **cmd)
{
    if (my_arrlen(cmd) != 4) {
        my_puterr("Wrong nb of parameters (add/sub)\n");
        return 84;
    }
    for (int i = 1; i < 4; ++i) {
        if (is_a_register(cmd[i]) == -1) {
            my_puterr("Invalid register (add/sub)\n");
            return 84;
        }
    }
    return 0;
}

int check_operator(char **cmd)
{
    if (my_arrlen(cmd) != 4) {
        my_puterr("Wrong nb of parameters (and/or/xor)\n");
        return 84;
    }
    if (is_a_register(cmd[3]) == -1) {
        my_puterr("Invalid register (and/or/xor)\n");
        return 84;
    }
    return 0;
}

int check_ldi(char **cmd)
{
    if (my_arrlen(cmd) != 4) {
        my_puterr("Wrong nb of parameters ((l)ldi)\n");
        return 84;
    }
    for (int i = 1; i < 3; ++i) {
        if (is_a_register(cmd[i]) == -1 && my_atoi(cmd[i]) == LEN_ERROR &&
            cmd[i][0] != '%' && cmd[i][0] != ':') {
            my_puterr("Invalid argument ((l)ldi)\n");
            return 84;
        }
    }
    if (is_a_register(cmd[3]) == -1) {
        my_puterr("Invalid register ((l)ldi)\n");
        return 84;
    }
    return 0;
}

int check_sti(char **cmd)
{
    if (my_arrlen(cmd) != 4) {
        my_puterr("Wrong nb of parameters (sti)\n");
        return 84;
    }
    if (is_a_register(cmd[1]) == -1) {
        my_puterr("Invalid register (sti)\n");
        return 84;
    }
    for (int i = 2; i < 4; ++i) {
        if (is_a_register(cmd[i]) == -1 && my_atoi(cmd[i]) == LEN_ERROR &&
            cmd[i][0] != '%' && cmd[i][0] != '%') {
            my_puterr("Invalid argument (sti)\n");
            return 84;
        }
    }
    return 0;
}
