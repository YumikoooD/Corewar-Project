/*
** EPITECH PROJECT, 2023
** utils
** File description:
** get args
*/

#include "my.h"
#include <stdlib.h>
#include <stdbool.h>
#include "vm.h"
#include "table.h"

int get_nb_bytes_arg(vm_t *data, int address, int nb)
{
    int value = 0;
    int adress = 0;

    if (nb == 2) {
        return (((data->arena[normalize_adress(NULL, address)] & 255) << 8)
        & 65280) + (data->arena[normalize_adress(NULL, address + 1)] & 255);
    }
    for (int i = 0; i < nb; i++) {
        adress = normalize_adress(NULL, address + i);
        value = (value << 8) + data->arena[adress];
    }
    return value;
}
