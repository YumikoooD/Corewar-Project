/*
** EPITECH PROJECT, 2023
** asm corewar
** File description:
** utils error handling
*/

#include "my.h"
#include "op.h"

int is_a_register(char *param)
{
    int reg_nb = 0;

    if (param[0] != 'r') {
        return -1;
    }
    param++;
    reg_nb = my_atoi(param);
    if (reg_nb < 0 || reg_nb > REG_NUMBER) {
        return -1;
    }
    return 0;
}
