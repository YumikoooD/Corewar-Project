/*
** EPITECH PROJECT, 2023
** asm corewar
** File description:
** error handling check 2 param
*/

#include "my.h"
#include "asm.h"
#include "op.h"

int get_ld_size(char **cmd)
{
    return OPCODE_SIZE + CODING_BYTE_SIZE +
        get_param_size(cmd[1]) + REG_SIZE;
}

int get_st_size(char **cmd)
{
    return OPCODE_SIZE + CODING_BYTE_SIZE +
        get_param_size(cmd[2]) + REG_SIZE;
}
