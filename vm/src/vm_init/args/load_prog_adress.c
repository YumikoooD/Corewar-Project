/*
** EPITECH PROJECT, 2022
** vm
** File description:
** load_prog_adress.c
*/

#include "my.h"
#include "vm.h"
#include "op.h"
#include <stdlib.h>

int load_prog_adress(char *str, vm_t *data)
{
    int nb = -1;

    for (int i = 0; str[i] != 0; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return ERROR;
    }
    if (!my_strcmp(str, "0")) {
        data->fighter_address = 0;
        return SUCCESS;
    }
    nb = my_atoi(str);
    if (nb == 0)
        return ERROR;
    for (int i = 0; data->fighter[i] != NULL; i++)
        if (data->fighter[i]->address == nb)
            return ERROR;
    if (nb % MEM_SIZE != 0 || data->fighter_address != -1)
        return ERROR;
    data->fighter_address = nb;
    return SUCCESS;
}
