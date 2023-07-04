/*
** EPITECH PROJECT, 2023
** utils
** File description:
** cpy fighter
*/

#include "my.h"
#include "vm.h"
#include <unistd.h>
#include <stdlib.h>

fighter_t *fighter_cpy(fighter_t *fighter, vm_t *data)
{
    fighter_t *new_fighter = malloc(sizeof(fighter_t));

    new_fighter->body_size = fighter->body_size;
    new_fighter->carry = fighter->carry;
    new_fighter->last_live_call = fighter->last_live_call;
    new_fighter->alive = fighter->alive;
    new_fighter->cycle_exec = fighter->cycle_exec;
    new_fighter->fighter_number = fighter->fighter_number;
    new_fighter->body = malloc(sizeof(char) * fighter->body_size);
    for (int i = 0; i < fighter->body_size; i++)
        new_fighter->body[i] =
                data->arena[normalize_adress(NULL, fighter->address + i)];
    new_fighter->name = my_strdup(fighter->name);
    new_fighter->comment = my_strdup(fighter->comment);
    new_fighter->reg = malloc(sizeof(int) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; i++)
        new_fighter->reg[i] = fighter->reg[i];
    return new_fighter;
}
