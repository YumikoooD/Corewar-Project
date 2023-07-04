/*
** EPITECH PROJECT, 2022
** MiniShell1
** File description:
** cmd_detector_main.c
*/

#include "my.h"
#include "vm.h"
#include "cmd_detector.h"
#include "table.h"
#include <unistd.h>
#include <stdbool.h>

int cmd_detector(vm_t *data, fighter_t *fighter, int opcode)
{
    int recup = 0;

    if (command[opcode - 1].opcode == opcode &&
            detect_error(data, fighter, opcode)) {
        recup = command[opcode - 1].detect(data, fighter);
        fighter->cycle_exec = data->actual_cycle;
    } else {
        normalize_pc(fighter, 1);
    }
    return recup;
}
