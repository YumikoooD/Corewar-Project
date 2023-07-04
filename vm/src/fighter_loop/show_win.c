/*
** EPITECH PROJECT, 2022
** vm
** File description:
** show_win.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdbool.h>
#include "vm.h"
#include "table.h"

void show_win(vm_t *data)
{
    if (data->fighter_alive == NULL) {
        my_printf("Equality\n");
        return;
    }
    my_printf("The player %d", data->fighter_alive->fighter_number);
    my_printf("(");
    my_printf("%s", data->fighter_alive->name);
    my_printf(")has won.\n", data->fighter_alive->name);
}
