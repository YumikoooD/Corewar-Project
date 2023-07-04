/*
** EPITECH PROJECT, 2022
** vm
** File description:
** cmd_live.c
*/

#include "my.h"
#include "vm.h"
#include <unistd.h>

void execute_sti_operation(fighter_t *fighter, int reg_value)
{
    if (reg_value == 0)
        fighter->carry = 1;
    else
        fighter->carry = 0;
}

int cmd_sti(vm_t *data, fighter_t *fighter)
{
    int address = normalize_adress(fighter, fighter->pc);
    int reg_value = get_arg_value_by_type_relative(data, REG,
                address + 2, fighter);
    args_type_t arg2_type = get_argument_type(data, address, 2);
    int arg2 = get_arg_value_by_type_relative(data, arg2_type, address + 2 +
            type_size(REG), fighter);
    args_type_t arg3_type = get_argument_type(data, address, 3);
    int arg3 = get_arg_value_by_type_relative(data, arg3_type, address + 2 +
            type_size(REG) + type_size(arg2_type), fighter);
    int add = arg2 + arg3;
    args_type_t args[] = {REG, arg2_type, arg3_type};

    write_nbytes(data, normalize_adress(NULL, address + add % IDX_MOD),
            reg_value, 4);
    execute_sti_operation(fighter, reg_value);
    update_pc(fighter, args, 3, 1);
    return 0;
}
