/*
** EPITECH PROJECT, 2022
** vm
** File description:
** cmd_live.c
*/

#include "my.h"
#include "vm.h"
#include <unistd.h>

int cmd_zjmp(vm_t *data, fighter_t *fighter)
{
    int address = normalize_adress(fighter, fighter->pc);
    int add = get_nb_bytes_arg(data, address + 1, 2);

    if (fighter->carry)
        normalize_pc(fighter, add);
    else
        normalize_pc(fighter, 3);
    return 0;
}
