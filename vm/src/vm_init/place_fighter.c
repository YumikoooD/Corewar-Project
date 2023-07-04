/*
** EPITECH PROJECT, 2022
** vm
** File description:
** place_fighter.c
*/

#include "my.h"
#include <stdlib.h>
#include "vm.h"
#include "op.h"

// int give_address(int address)
// {
//     address = (address % MEM_SIZE + MEM_SIZE) % MEM_SIZE;
//     return address;
// }

int buffer_overflow(vm_t *data)
{
    int total_size = 0;

    for (int i = 0; i < data->fighter_nbr; i++) {
        total_size += data->fighter[i]->body_size;
    }
    if (total_size > MEM_SIZE) {
        return ERROR;
    }
    return SUCCESS;
}

int address_setup(vm_t *data, fighter_t *fighter, int address)
{
    int address_index = 0;

    for (int i = 0; i < fighter->body_size; i++) {
        address_index = normalize_adress(NULL, i + address);
        data->arena[address_index] = fighter->body[i];
    }
    fighter->address = address;
    return SUCCESS;
}

int place_fighter(vm_t *data)
{
    int arena_size = MEM_SIZE;
    int bytes_per_fighter = 0;
    int address = 0;

    if (data->fighter == NULL)
        return ERROR;
    if (buffer_overflow(data) == ERROR)
        return ERROR;
    bytes_per_fighter = arena_size / data->fighter_nbr;
    for (int i = 0; i < data->fighter_nbr; i++) {
        if (data->fighter[i]->address != -1)
            continue;
        if (address != 0)
            address += bytes_per_fighter;
        else
            address = 0;
        address_setup(data, data->fighter[i], address);
        address += data->fighter[i]->body_size;
    }
    return SUCCESS;
}
