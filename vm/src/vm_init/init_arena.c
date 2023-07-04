/*
** EPITECH PROJECT, 2022
** vm
** File description:
** init_arena.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "op.h"

int init_arena(vm_t *data)
{
    data->arena = malloc(sizeof(int) * MEM_SIZE);
    if (data->arena == NULL)
        return ERROR;
    for (int i = 0; i < MEM_SIZE; i++)
        data->arena[i] = 0;
    return SUCCESS;
}
