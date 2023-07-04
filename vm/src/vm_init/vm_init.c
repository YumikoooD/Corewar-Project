/*
** EPITECH PROJECT, 2022
** vm
** File description:
** vm_init.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "op.h"

int vm_init(vm_t *data, int ac, char **av)
{
    if (error_input(data, ac, av) == ERROR)
        return ERROR;
    if (init_arena(data) == ERROR)
        return ERROR;
    if (init_flags(data, ac, av) == ERROR)
        return ERROR;
    if (data->dump_nbr_cycle == 0)
        data->dump_nbr_cycle = CYCLE_TO_DIE;
    if (place_fighter(data) == ERROR)
        return ERROR;
    return SUCCESS;
}
