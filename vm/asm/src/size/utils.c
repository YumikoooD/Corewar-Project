/*
** EPITECH PROJECT, 2023
** asm corewar
** File description:
** utils size
*/

#include "my.h"
#include "op.h"

int get_param_size(char *param)
{
    if (param[0] == 'r')
        return REG_SIZE;
    if (param[0] == '%')
        return DIR_SIZE;
    else
        return IND_SIZE;
}
