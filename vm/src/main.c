/*
** EPITECH PROJECT, 2022
** src
** File description:
** main.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdbool.h>
#include "vm.h"
#include "table.h"

int corewar_game(int ac, char **av)
{
    vm_t *data = malloc(sizeof(vm_t));

    if (data == NULL)
        return ERROR;
    if (vm_init(data, ac, av) == ERROR)
        return ERROR;
    while (data->fighter_nbr > 1 && data->actual_cycle <=
        data->dump_nbr_cycle && data->dump_nbr_cycle > 0) {
        sort_fighters_bubble(data->fighter, data->fighter_nbr);
        fighter_fight(data);
        partition_alive_dead(data->fighter);
        find_dead_fighters(data);
        data->actual_cycle++;
    }
    show_win(data);
    destroy(data);
    return SUCCESS;
}

int main(int ac, char **av)
{
    if (ac == 2)
        if (!my_strcmp(av[1], "-h")) {
            show_help();
            return SUCCESS;
        }
    if (ac < 3)
        return ERROR;
    if (corewar_game(ac, av) == ERROR)
        return ERROR;
    return SUCCESS;
}
