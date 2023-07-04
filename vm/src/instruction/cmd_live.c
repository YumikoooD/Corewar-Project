/*
** EPITECH PROJECT, 2022
** vm
** File description:
** cmd_live.c
*/

#include "my.h"
#include "vm.h"
#include <unistd.h>
#include <stdio.h>
#include "op.h"

int cmd_live(vm_t *data, fighter_t *fighter)
{
    int arg = get_nb_bytes_arg(data,
            normalize_adress(fighter, fighter->pc) + 1, 4);

    for (int i = 0; data->fighter[i] != NULL; i++)
        if (data->fighter[i]->fighter_number == arg)
            data->fighter[i]->last_live_call = data->actual_cycle;
    data->live_call += 1;
    if (data->live_call >= NBR_LIVE) {
        data->max_cycle -= CYCLE_DELTA;
        data->live_call = 0;
    }
    if (arg == fighter->fighter_number) {
        my_printf("The player %d", fighter->fighter_number);
        my_printf("(");
        my_printf("%s", fighter->name);
        my_printf(")is alive.\n");
        data->fighter_alive = fighter;
    }
    normalize_pc(fighter, 5);
    return 0;
}
