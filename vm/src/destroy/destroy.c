/*
** EPITECH PROJECT, 2022
** vm
** File description:
** destroy.c
*/

#include "my.h"
#include <stdlib.h>
#include "vm.h"

void destroy_fighter(fighter_t **fighter, int fighter_nbr)
{
    for (int i = 0; i < fighter_nbr; i++) {
        if (fighter[i]->name != NULL)
            free(fighter[i]->name);
        if (fighter[i]->comment != NULL)
            free(fighter[i]->comment);
        if (fighter[i]->body != NULL)
            free(fighter[i]->body);
        if (fighter[i]->reg != NULL)
            free(fighter[i]->reg);
        if (fighter[i] != NULL)
            free(fighter[i]);
    }
    if (fighter != NULL)
        free(fighter);
}

void destroy(vm_t *data)
{
    destroy_fighter(data->fighter, data->fighter_nbr);
    free(data->arena);
    free(data);
}
