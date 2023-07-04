/*
** EPITECH PROJECT, 2022
** vm
** File description:
** init_data.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "op.h"

void init_data(vm_t *data)
{
    data->fighter = NULL;
    data->fighter_alive = NULL;
    data->fighter_address = -1;
    data->prog_number = -1;
    data->dump_nbr_cycle = 0;
    data->fighter_nbr = 0;
    data->actual_cycle = 0;
    data->live_call = 0;
}
