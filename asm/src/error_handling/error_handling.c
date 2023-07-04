/*
** EPITECH PROJECT, 2023
** error handling
** File description:
** asm corewar
*/

#include "my.h"
#include <stdlib.h>

void remove_commentary(char **cmd)
{
    int i = 0;

    while (cmd[i] != NULL) {
        if (cmd[i][0] == '#')
            break;
        ++i;
    }
    while (cmd[i] != NULL) {
        free(cmd[i]);
        cmd[i] = NULL;
        ++i;
    }
}

int verify_filename(char *filename)
{
    int len = my_strlen(filename);
    int ext_len = my_strlen(".s");

    if (my_strcmp(filename + len - ext_len, ".s") != 0)
        return 84;
    return 0;
}

int error_handling(int ac, char **av)
{
    if (ac != 2) {
        my_puterr("Wrong number of arguments (cf ./asm -h)\n");
        return 84;
    }
    if (verify_filename(av[1]) == 84) {
        my_puterr("Wrong filename (cf ./asm -h)\n");
        return 84;
    }
    return 0;
}
