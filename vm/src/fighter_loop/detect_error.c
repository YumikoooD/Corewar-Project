/*
** EPITECH PROJECT, 2022
** MiniShell1
** File description:
** detect error.c
*/

#include "my.h"
#include "vm.h"
#include "table.h"
#include <unistd.h>
#include <stdbool.h>

bool is_reg(int opcode)
{
    switch (opcode) {
        case 1:
            return false;
        case 9:
            return false;
        case 12:
            return false;
        case 15:
            return false;
        default:
            return true;
    }
}

bool check_args_types(vm_t *data, int address, int opcode)
{
    int args[3] = {0, 0, 0};
    int type = 0;

    for (int i = 0; i < op_tab[opcode - 1].nbr_args; i++)
        args[i] = type_size(get_argument_type(data, address, i + 1));
    for (int i = 0; i < op_tab[opcode - 1].nbr_args; i++) {
        type = op_tab[opcode - 1].type[i];
        if ((type & T_REG) != 0 && args[i] != T_REG &&
            (type & T_DIR) != 0 && args[i] != T_DIR &&
            (type & T_IDX) != 0 && args[i] != T_IDX) {
            return false;
        }
    }
    return true;
}

int size_get_type(vm_t *data, int address, int opcode, int i)
{
    args_type_t arg_type = op_tab[opcode - 1].type[i - 1];

    if (!is_reg(opcode) || !get_argument_type(data, address, i)) {
        if ((arg_type & T_REG) == T_REG)
            return T_REG;
        if ((arg_type & 2) == 2)
            return 2;
        if ((arg_type & T_IDX) == T_IDX)
            return T_IDX;
        return T_REG;
    }
    return type_size(get_argument_type(data, address, i));
}

bool verify_registers(vm_t *data, int address, int opcode)
{
    int size = T_DIR;
    int output = 0;

    if (!is_reg(opcode))
        size = T_REG;
    for (int i = 0; i < op_tab[opcode - 1].nbr_args; i++) {
        output = size_get_type(data, address, opcode, i + 1);
        if (output == T_REG &&
                (data->arena[normalize_adress(NULL, size + address)] > 16 ||
                data->arena[normalize_adress(NULL, size + address)] < 1)) {
            return false;
        }
        size += output;
    }
    return true;
}

bool detect_error(vm_t *data, fighter_t *fighter, int opcode)
{
    int address = normalize_adress(fighter, fighter->pc);

    if (opcode < 1 || opcode > 16)
        return false;
    if (verify_registers(data, address, opcode) == false) {
        return false;
    }
    if (check_args_types(data, address, opcode) == false) {
        return false;
    }
    return true;
}
