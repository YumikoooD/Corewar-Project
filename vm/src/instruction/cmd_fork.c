/*
** EPITECH PROJECT, 2022
** vm
** File description:
** cmd_live.c
*/

#include "my.h"
#include "vm.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int cmd_fork(vm_t *data, fighter_t *fighter)
{
    fighter_t *new_fighter = fighter_cpy(fighter, data);
    int address = normalize_adress(fighter, fighter->pc);
    int arg = get_arg_value_by_type(data, 2, address + 1, fighter);

    new_fighter->pc = fighter->pc + arg % IDX_MOD;
    address_setup(data, new_fighter, address +
            new_fighter->body_size + arg % IDX_MOD);
    add_fighter(&data->fighter, new_fighter, data);
    normalize_pc(fighter, 3);
    return 0;
}
