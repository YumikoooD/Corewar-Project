/*
** EPITECH PROJECT, 2022
** vm
** File description:
** error_input.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "op.h"

int get_flag_nbr(int ac, char **av)
{
    int flag_nbr = 0;

    for (int i = 0; i < ac; i++) {
        if (av[i][0] == '-') {
            flag_nbr++;
        }
    }
    return flag_nbr;
}

int error_input(vm_t *data, int ac, char **av)
{
    char **temp = get_cor_file(ac, av, data);
    int cor_nbr = get_number_file(ac, av, data);
    int flag_nbr = get_flag_nbr(ac, av);
    int result = ac - 1;

    for (int i = 0; i < ac; i++) {
        if (my_strcmp(av[i], "-dump") == 0)
            result -= 1;
    }
    if (temp == NULL) {
        return ERROR;
    }
    result = result - flag_nbr - cor_nbr;
    free_tab(temp);
    if (result != 0) {
        return ERROR;
    }
    return SUCCESS;
}
