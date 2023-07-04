/*
** EPITECH PROJECT, 2022
** vm
** File description:
** cmd_live.c
*/

#include "my.h"
#include "vm.h"
#include "table.h"
#include <unistd.h>

void execute_and_operation(fighter_t *fighter, int arg1, int arg2, int reg)
{
    int result = arg1 & arg2;

    fighter->reg[reg - 1] = result;
    if (result == 0)
        fighter->carry = 1;
    else
        fighter->carry = 0;
}

int cmd_and(vm_t *data, fighter_t *fighter)
{
    int address = normalize_adress(fighter, fighter->pc);
    args_type_t arg1_type = get_argument_type(data, address, 1);
    int arg1 = get_arg_value_by_type_relative(data, arg1_type, address + 2,
            fighter);
    args_type_t arg2_type = get_argument_type(data, address, 2);
    int arg2 = get_arg_value_by_type_relative(data, arg2_type, address + 2 +
            type_size(arg1_type), fighter);
    int reg = data->arena[normalize_adress(NULL, address + 2 +
            type_size(arg1_type) + type_size(arg2_type))];
    args_type_t args[] = {arg1_type, arg2_type, 1};

    execute_and_operation(fighter, arg1, arg2, reg);
    update_pc(fighter, args, 3, 1);
    return 0;
}
