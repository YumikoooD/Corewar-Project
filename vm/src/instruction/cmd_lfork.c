/*
** EPITECH PROJECT, 2022
** vm
** File description:
** cmd_live.c
*/

#include "my.h"
#include "vm.h"
#include <unistd.h>

int cmd_lfork(vm_t *data, fighter_t *fighter)
{
    fighter_t *new_fighter = fighter_cpy(fighter, data);
    int address = normalize_adress(fighter, fighter->pc);
    int arg = get_arg_value_by_type(data, DIR, address + 1, fighter);

    new_fighter->pc = arg + new_fighter->body_size;
    new_fighter->address = address + new_fighter->body_size + arg;
    address_setup(data, new_fighter, new_fighter->address);
    add_fighter(&data->fighter, new_fighter, data);
    normalize_pc(fighter, 3);
    return 0;
}
