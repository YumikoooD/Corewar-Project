/*
** EPITECH PROJECT, 2022
** vm
** File description:
** load_prog_nb.c
*/

#include "my.h"
#include "vm.h"
#include <stdlib.h>

int load_prog_number(char *str, vm_t *data)
{
    int nb = -1;

    for (int i = 0; str[i] != 0; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return ERROR;
    }
    if (!my_strcmp(str, "0")) {
        data->prog_number = 0;
        return SUCCESS;
    }
    nb = my_atoi(str);
    if (nb == 0)
        return ERROR;
    for (int i = 0; data->fighter[i] != NULL; i++)
        if (data->fighter[i]->fighter_number == nb)
            return ERROR;
    if (data->prog_number != -1)
        return ERROR;
    data->prog_number = nb;
    return SUCCESS;
}
