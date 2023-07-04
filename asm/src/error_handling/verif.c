/*
** EPITECH PROJECT, 2023
** verif
** File description:
** corewar asm
*/

#include "asm.h"
#include <stdio.h>
#include "op.h"
#include <stdlib.h>
#include "my.h"
#include "error_handling.h"

char *skip_label(char *line)
{
    if (is_a_label(line) == 0) {
        for (; *line != ':'; ++line);
        ++line;
    }
    return line;
}

int verif_line(char *line)
{
    char **cmd = NULL;
    int error = 0;

    line = skip_label(line);
    cmd = get_word_arr(line);
    if (cmd == NULL)
        return 84;
    remove_commentary(cmd);
    if (cmd[0] == NULL)
        return 0;
    for (int i = 0; i < NB_INSTRUCTIONS; ++i) {
        if (my_strcmp(mnemonique[i], cmd[0]) == 0) {
            error = (check_tab[i])(cmd);
            free_tab(cmd);
            return error;
        }
    }
    free_tab(cmd);
    my_puterr("command not found\n");
    return 84;
}

int verif_file(FILE *asm_stream)
{
    size_t getline_size = 0;
    char *line = NULL;

    fseek(asm_stream, 0, SEEK_SET);
    for (int i = 0; i < 2; ++i) {
        if (getline(&line, &getline_size, asm_stream) == -1)
            return 84;
        if (line[0] == '#' || line[0] == '\n')
            --i;
    }
    while (getline(&line, &getline_size, asm_stream) != -1) {
        if (line[0] == '\n' || line[0] == '\0' || line[0] == '#')
            continue;
        if (verif_line(line) == 84) {
            return 84;
        }
    }
    if (line)
        free(line);
    return 0;
}
