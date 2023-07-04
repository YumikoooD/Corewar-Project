/*
** EPITECH PROJECT, 2022
** vm
** File description:
** fighter_fight.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdbool.h>
#include "vm.h"
#include "table.h"

void fighter_fight(vm_t *data)
{
    int exec_command;
    int nbr_cycles;

    if (data->fighter == NULL)
        return;
    for (int i = 0; data->fighter[i] != NULL; i++) {
        exec_command = data->arena[normalize_adress(data->fighter[i],
                data->fighter[i]->pc)];
        if (exec_command < 1 || exec_command > 16) {
            normalize_pc(data->fighter[i], 1);
            continue;
        }
        nbr_cycles = op_tab[exec_command - 1].nbr_cycles;
        if (data->fighter[i]->cycle_exec == -1 ||
            data->actual_cycle - data->fighter[i]->cycle_exec >= nbr_cycles) {
            cmd_detector(data, data->fighter[i], exec_command);
        }
    }
}
