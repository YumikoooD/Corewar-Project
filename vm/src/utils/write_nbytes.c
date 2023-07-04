/*
** EPITECH PROJECT, 2023
** utils
** File description:
** write_nbytes
*/

#include "my.h"
#include "vm.h"
#include <unistd.h>

void write_nbytes(vm_t *data, int address, int value, int nb)
{
    int shift;
    int byte;

    for (int i = 0; i < nb; i++) {
        shift = 8 * (nb - i - 1);
        byte = (value >> shift) & 255;
        data->arena[normalize_adress(NULL, address + i)] = byte;
    }
}
