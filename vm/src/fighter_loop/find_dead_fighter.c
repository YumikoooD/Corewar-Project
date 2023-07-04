/*
** EPITECH PROJECT, 2022
** vm
** File description:
** find_dead_fighter.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdbool.h>
#include "vm.h"
#include "table.h"

void find_dead_fighters(vm_t *data)
{
    for (int i = 0; data->fighter[i] != NULL; i++) {
        if (data->actual_cycle - data->fighter[i]->last_live_call
                > data->dump_nbr_cycle) {
            data->fighter[i]->alive = 0;
            data->fighter_nbr--;
        }
    }
}
