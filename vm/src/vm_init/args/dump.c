/*
** EPITECH PROJECT, 2022
** vm
** File description:
** dump.c
*/

#include "my.h"
#include "vm.h"
#include <stdlib.h>

int hexa_to_int(char *hexa)
{
    int result = 0;

    for (int i = 0; hexa[i] != 0; i++) {
        result = result * 16;
        if (hexa[i] >= '0' && hexa[i] <= '9')
            result += hexa[i] - '0';
        if (hexa[i] >= 'A' && hexa[i] <= 'F')
            result += hexa[i] - 'A' + 10;
    }
    return result;
}

int load_dump(char *str, vm_t *data)
{
    int dump_nbr_cycle = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (!((str[i] >= '0' && str[i] <= '9') ||
                (str[i] >= 'A' && str[i] <= 'F')))
            return ERROR;
    }
    dump_nbr_cycle = hexa_to_int(str);
    if (dump_nbr_cycle == 0)
        return ERROR;
    data->dump_nbr_cycle = dump_nbr_cycle;
    return SUCCESS;
}
