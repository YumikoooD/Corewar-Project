/*
** EPITECH PROJECT, 2023
** corewar asm
** File description:
** asm
*/

#include "asm.h"
#include <stdio.h>
#include "op.h"
#include <stdlib.h>
#include "my.h"
#include "error_handling.h"

int write_file(char *line, stream_t *streams, label_t *labels)
{
    int nb_bytes = 0;
    size_t getline_size = 0;

    while (getline(&line, &getline_size, streams->asm_stream) != -1) {
        if (line[0] == '\n' || line[0] == '\0' || line [0] == '#')
            continue;
        if (write_line(line, streams, labels, nb_bytes) == 84)
            return 84;
        nb_bytes += count_bytes(line);
    }
    return 0;
}

int run_asm(stream_t *streams)
{
    label_t *labels = NULL;
    size_t getline_size = 0;
    char *line = NULL;

    labels = get_all_label(streams->asm_stream);
    if (labels == NULL)
        return 84;
    fseek(streams->asm_stream, 0, SEEK_SET);
    for (int i = 0; i < 2; ++i) {
        getline(&line, &getline_size, streams->asm_stream);
        if (line[0] == '#' || line[0] == '\n')
            --i;
    }
    write_file(line, streams, labels);
    if (line)
        free(line);
    free_label(&labels);
    return 0;
}
