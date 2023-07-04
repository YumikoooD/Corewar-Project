/*
** EPITECH PROJECT, 2023
** asm corewar
** File description:
** body
*/

#include "asm.h"
#include <stdio.h>
#include "op.h"
#include <stdlib.h>
#include "my.h"
#include "error_handling.h"
#include <unistd.h>

int write_parameters(char *parameter, stream_t *streams,
                    label_t *labels, int nb_bytes)
{
    if (parameter[0] == 'r')
        return write_reg(parameter, streams);
    if (parameter[0] == '%')
        return write_dir(parameter, streams, labels, nb_bytes);
    return write_ind(parameter, streams, labels, nb_bytes);
}

int is_a_comment(char *line)
{
    if (line[0] == '#' || line[0] == '\0' || line[0] == '\n')
        return 0;
    return -1;
}

int is_index_command(char *cmd)
{
    for (int i = 0; i < 6; ++i) {
        if (my_strcmp(cmd, index_cmd[i]) == 0)
            return 0;
    }
    return -1;
}

int check_parameters_type(char **cmd, stream_t *streams,
    label_t *labels, int nb_bytes)
{
    if (cmd[0] == NULL)
        return 0;
    for (int i = 1; cmd[i] != NULL; ++i) {
        if (is_index_command(cmd[0]) == 0 &&
            write_index(cmd[i], streams, labels, nb_bytes) == 84)
            return 84;
        if (is_index_command(cmd[0]) != 0 &&
            write_parameters(cmd[i], streams, labels, nb_bytes) == 84)
            return 84;
    }
    return 0;
}

int write_line(char *line, stream_t *streams, label_t *labels, int nb_bytes)
{
    char **cmd = NULL;

    if (is_a_comment(line) == 0)
        return 0;
    if (is_a_label(line) == 0) {
        for (; *line != ':'; ++line);
        ++line;
    }
    if (check_command(line, streams) == 84)
        return 84;
    cmd = get_word_arr(line);
    if (cmd == NULL)
        return 84;
    remove_commentary(cmd);
    if (check_parameters_type(cmd, streams, labels, nb_bytes) == 84)
        return 84;
    free_tab(cmd);
    return 0;
}
