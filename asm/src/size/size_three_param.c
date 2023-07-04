/*
** EPITECH PROJECT, 2023
** asm corewar
** File description:
** check 3 params
*/

#include "asm.h"
#include "my.h"
#include "op.h"

int get_add_sub_size(char **cmd)
{
    return OPCODE_SIZE + CODING_BYTE_SIZE + get_param_size(cmd[1]) * 3;
}

int get_operator_size(char **cmd)
{
    return OPCODE_SIZE + CODING_BYTE_SIZE + get_param_size(cmd[1]) +
        get_param_size(cmd[2]) + REG_SIZE;
}

int get_ldi_size(char **cmd)
{
    int size = OPCODE_SIZE + CODING_BYTE_SIZE + REG_SIZE;

    if (cmd[1][0] == 'r')
        size += REG_SIZE;
    else
        size += IND_SIZE;
    if (cmd[2][0] == 'r')
        size += REG_SIZE;
    else
        size += IND_SIZE;
    return size;
}

int get_sti_size(char **cmd)
{
    int size = OPCODE_SIZE + CODING_BYTE_SIZE + REG_SIZE;

    if (cmd[2][0] == 'r')
        size += REG_SIZE;
    else
        size += IND_SIZE;
    if (cmd[3][0] == 'r')
        size += REG_SIZE;
    else
        size += IND_SIZE;
    return size;
}
