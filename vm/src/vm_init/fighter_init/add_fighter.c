/*
** EPITECH PROJECT, 2022
** vm
** File description:
** add fighter.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "op.h"

void add_fighter(fighter_t ***fighter, fighter_t *to_add, vm_t *data)
{
    int len = data->fighter_nbr;
    fighter_t **fighter_tmp = malloc(sizeof(fighter_t *) * (len + 2));

    for (int i = 0; i < len; i++)
        fighter_tmp[i] = (*fighter)[i];
    fighter_tmp[len] = to_add;
    fighter_tmp[len + 1] = NULL;
    free(*fighter);
    *fighter = fighter_tmp;
    data->fighter_nbr++;
}
