/*
** EPITECH PROJECT, 2022
** vm
** File description:
** asm_fighter.c
*/

#include "my.h"
#include "op.h"
#include <stdlib.h>
#include "vm.h"

int fighter_create(vm_t *data, fighter_t *fighter, char *buffer)
{
    if (get_cor(fighter, buffer) == ERROR)
        return ERROR;
    if (data->prog_number != -1)
        fighter->fighter_number = data->prog_number;
    else
        fighter->fighter_number = data->fighter_nbr;
    fighter->address = data->fighter_address;
    fighter->reg = malloc(sizeof(int) * REG_NUMBER);
    if (fighter->reg == NULL)
        return ERROR;
    for (int i = 0; i < REG_NUMBER; i++)
        fighter->reg[i] = 0;
    fighter->reg[0] = fighter->fighter_number;
    fighter->alive = true;
    fighter->carry = false;
    fighter->cycle_exec = -1;
    fighter->last_live_call = 0;
    fighter->pc = 0;
    return SUCCESS;
}

int asm_fighter(vm_t *data, fighter_t *fighter, char *file)
{
    char *buffer = NULL;

    buffer = getline_file(file);
    if (buffer == NULL)
        return ERROR;
    if (fighter_create(data, fighter, buffer) == ERROR)
        return ERROR;
    free(buffer);
    return SUCCESS;
}
