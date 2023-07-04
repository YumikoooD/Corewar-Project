/*
** EPITECH PROJECT, 2022
** utils
** File description:
** adress.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdbool.h>
#include "vm.h"
#include "table.h"

int normalize_adress(fighter_t *fighter, int to_add)
{
    int address = 0;

    if (fighter != NULL)
        address = to_add + fighter->address;
    else
        address = to_add;
    while (address >= MEM_SIZE)
        address -= MEM_SIZE;
    while (address < 0)
        address += MEM_SIZE;
    return address;
}
