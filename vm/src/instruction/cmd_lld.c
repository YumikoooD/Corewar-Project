/*
** EPITECH PROJECT, 2022
** vm
** File description:
** cmd_live.c
*/

#include "my.h"
#include "vm.h"
#include <unistd.h>

void execute_lld_operation(fighter_t *fighter, int arg1, int reg)
{
    fighter->reg[reg - 1] = arg1;
    if (arg1 == 0)
        fighter->carry = 1;
    else
        fighter->carry = 0;
}

int cmd_lld(vm_t *data, fighter_t *fighter)
{
    int address = normalize_adress(fighter, fighter->pc);
    args_type_t arg1_type = get_argument_type(data, address, 1);
    int arg1 = get_arg_value_by_type(data, arg1_type, address + 2, fighter);
    int reg = data->arena[normalize_adress(NULL, address + 2 +
            type_size(arg1_type))];
    args_type_t args[] = {arg1_type, 1};

    execute_lld_operation(fighter, arg1, reg);
    update_pc(fighter, args, 2, 1);
    return 0;
}
