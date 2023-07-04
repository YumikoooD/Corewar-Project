/*
** EPITECH PROJECT, 2022
** vm
** File description:
** cmd_live.c
*/

#include "my.h"
#include "vm.h"
#include <unistd.h>

void execute_ldi_operation(fighter_t *fighter, int reg, int value)
{
    fighter->reg[reg - 1] = value;
    if (value == 0)
        fighter->carry = 1;
    else
        fighter->carry = 0;
}

int cmd_ldi(vm_t *data, fighter_t *fighter)
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
    int value = get_nb_bytes_arg(data, address +
            (arg1 + arg2) % IDX_MOD, 4);
    args_type_t args[] = {arg1_type, arg2_type, 1};

    execute_ldi_operation(fighter, reg, value);
    update_pc(fighter, args, 3, 1);
    return 0;
}
