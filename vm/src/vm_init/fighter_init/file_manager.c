/*
** EPITECH PROJECT, 2022
** vm
** File description:
** file_manager.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "op.h"

int file_manager(vm_t *data, char *file)
{
    fighter_t *fighter = malloc(sizeof(fighter_t));

    if (asm_fighter(data, fighter, file) == ERROR)
        return ERROR;
    add_fighter(&data->fighter, fighter, data);
    data->fighter_address = -1;
    data->prog_number = -1;
    return SUCCESS;
}
