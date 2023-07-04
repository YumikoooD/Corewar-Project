/*
** EPITECH PROJECT, 2022
** vm
** File description:
** flags_manager.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "op.h"

int flags_manager(vm_t *data, char **av, int ac, int i)
{
    if (i + 1 == ac)
        return ERROR;
    if (!my_strcmp(av[i], "-dump"))
        return load_dump(av[i + 1], data);
    if (!my_strcmp(av[i], "-n"))
        return load_prog_number(av[i + 1], data);
    if (!my_strcmp(av[i], "-a"))
        return load_prog_adress(av[i + 1], data);
    return ERROR;
}

int init_flags(vm_t *data, int ac, char **av)
{
    int return_value = 0;

    init_data(data);
    for (int i = 1; i < ac; i++) {
        if (return_value == ERROR)
            return ERROR;
        if (av[i][0] == '-') {
            return_value = flags_manager(data, av, ac, i);
            i++;
            continue;
        }
        if (file_manager(data, av[i]) == ERROR)
            return ERROR;
    }
    if (return_value == ERROR)
        return ERROR;
    return SUCCESS;
}
