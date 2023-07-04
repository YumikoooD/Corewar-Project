/*
** EPITECH PROJECT, 2022
** vm
** File description:
** cmd_live.c
*/

#include "my.h"
#include "vm.h"
#include <unistd.h>

void execute_st_operation(fighter_t *fighter, int reg_value)
{
    if (reg_value == 0)
        fighter->carry = 1;
    else
        fighter->carry = 0;
}

int cmd_st(vm_t *data, fighter_t *fighter)
{
    int address = normalize_adress(fighter, fighter->pc);
    int reg_value = get_arg_value_by_type_relative(data, REG,
            address + 2, fighter);
    args_type_t arg2_type = get_argument_type(data, address, 2);
    int arg2 = get_arg_value_by_type_relative(data, arg2_type, address + 2 +
            type_size(REG), fighter);
    args_type_t args[] = {REG, arg2_type};

    if (arg2_type == REG) {
        arg2 = data->arena[normalize_adress(NULL, address + 3)];
        fighter->reg[arg2 - 1] = reg_value;
    } else {
        write_nbytes(data, normalize_adress(NULL,
                fighter->pc + arg2 % IDX_MOD), reg_value, 4);
    }
    execute_st_operation(fighter, reg_value);
    update_pc(fighter, args, 2, 1);
    return 0;
}
