/*
** EPITECH PROJECT, 2023
** utils
** File description:
** type arg
*/

#include "my.h"
#include <stdlib.h>
#include <stdbool.h>
#include "vm.h"
#include "table.h"

int type_size(args_type_t arg_type)
{
    if (arg_type == REG)
        return T_REG;
    if (arg_type == DIR)
        return T_DIR;
    if (arg_type == IND)
        return T_IND;
    if (arg_type == IDX)
        return T_IDX;
    return 0;
}

int get_arg_value_by_type(vm_t *data, args_type_t type,
int address, fighter_t *fighter)
{
    int new_address;

    switch (type) {
        case REG:
            return fighter->reg[data->arena[normalize_adress(NULL, address)]
                    - 1];
        case DIR:
            return get_nb_bytes_arg(data, address, T_DIR);
        case IND:
            new_address = get_nb_bytes_arg(data, address, 2) +
                            fighter->address + fighter->pc;
            return get_nb_bytes_arg(data,
                    normalize_adress(NULL, new_address), 4);
        default:
            return get_nb_bytes_arg(data, address, T_IDX);
    }
}

int get_arg_value_by_type_relative(vm_t *data, args_type_t type,
int address, fighter_t *fighter)
{
    int new_address;

    switch (type) {
        case REG:
            return fighter->reg[data->arena[normalize_adress(NULL, address)]
                    - 1];
        case DIR:
            return get_nb_bytes_arg(data, address, T_DIR);
        case IND:
            new_address = get_nb_bytes_arg(data, address, 2) % IDX_MOD +
                            fighter->address + fighter->pc;
            return get_nb_bytes_arg(data, normalize_adress(NULL,
                    new_address), 4);
        default:
            return get_nb_bytes_arg(data, address, T_IDX);
    }
}

int get_result(int value)
{
    if (value == IDX)
        return DIR;
    return value;
}

args_type_t get_argument_type(vm_t *data, int exec_address, int arg)
{
    int exec_cmd = data->arena[normalize_adress(NULL, exec_address)] - 1;
    int cbyte = data->arena[normalize_adress(NULL, exec_address + 1)];
    int arg_values[3] = {(cbyte >> 6) & 3, (cbyte >> 4) & 3, (cbyte >> 2) & 3};
    int result = arg_values[arg - 1];

    for (int i = 0; i < 3; i++)
        if (!(op_tab[exec_cmd].type[result] & T_IDX) && result == T_DIR)
            result = IDX;
    return result;
}
