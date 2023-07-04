/*
** EPITECH PROJECT, 2022
** vm
** File description:
** get_cor_file.c
*/

#include "my.h"
#include <stdlib.h>
#include <string.h>
#include "vm.h"

int get_number_file(int ac, char **av, vm_t *data)
{
    int size = 0;

    for (int i = 0; i < ac; i++) {
        if (my_strncmp(av[i] + my_strlen(av[i]) - 4, ".cor", 4) == 0) {
            size++;
        }
    }
    data->fighter_nbr = size;
    return size;
}

char **get_cor_file(int ac, char **av, vm_t *data)
{
    char **file = NULL;
    int size = get_number_file(ac, av, data);
    int len = 0;
    int j = 0;

    if (size < 2)
        return NULL;
    file = malloc(sizeof(char *) * (size + 1));
    if (file == NULL)
        return NULL;
    for (int i = 0; i < ac; i++) {
        if (my_strncmp(av[i] + my_strlen(av[i]) - 4, ".cor", 4) == 0) {
            len = my_strlen(av[i]) + 1;
            file[j] = malloc(sizeof(char) * len);
            my_strcpy(file[j], av[i]);
            j++;
        }
    }
    file[j] = NULL;
    return file;
}
