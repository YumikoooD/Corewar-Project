/*
** EPITECH PROJECT, 2022
** vm
** File description:
** cmd_live.c
*/

#include "my.h"
#include "vm.h"
#include <unistd.h>

int cmd_add(vm_t *data, fighter_t *fighter)
{
    int address = normalize_adress(fighter, fighter->pc);
    int arg1 = get_arg_value_by_type(data, REG, address + 2, fighter);
    int arg2 = get_arg_value_by_type(data, REG, address + 3, fighter);
    int result = arg1 + arg2;
    int registers = data->arena[normalize_adress(NULL, address + 4)];

    fighter->reg[registers - 1] = result;
    if (result == 0)
        fighter->carry = 1;
    else
        fighter->carry = 0;
    normalize_pc(fighter, 5);
    return 0;
}
