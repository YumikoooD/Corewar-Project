/*
** EPITECH PROJECT, 2022
** vm
** File description:
** cmd_live.c
*/

#include "my.h"
#include "vm.h"
#include <unistd.h>

int cmd_aff(vm_t *data, fighter_t *fighter)
{
    int address = normalize_adress(fighter, fighter->pc);
    int reg = get_arg_value_by_type(data, REG, address + 2, fighter);
    char c = reg % 256;

    my_putchar(c);
    if (c == 0)
        fighter->carry = 1;
    else
        fighter->carry = 0;
    normalize_pc(fighter, 3);
    return 0;
}
