/*
** EPITECH PROJECT, 2023
** error handling one param
** File description:
** asm corewar
*/

#include "my.h"
#include "op.h"
#include "asm.h"

int get_live_size(char **cmd)
{
    get_param_size(cmd[1]);
    return OPCODE_SIZE + DIR_SIZE;
}

int get_zjmp_size(char **cmd)
{
    get_param_size(cmd[1]);
    return OPCODE_SIZE + IND_SIZE;
}

int get_aff_size(char **cmd)
{
    get_param_size(cmd[1]);
    return OPCODE_SIZE + CODING_BYTE_SIZE + REG_SIZE;
}

int get_fork_size(char **cmd)
{
    get_param_size(cmd[1]);
    return OPCODE_SIZE + IND_SIZE;
}
