/*
** EPITECH PROJECT, 2023
** corewar asm
** File description:
** get label
*/

#include "op.h"
#include "asm.h"
#include "size.h"
#include "my.h"
#include <stdlib.h>

int count_bytes(char *line)
{
    char **cmd = NULL;
    int nb_bytes = 0;

    line = skip_label(line);
    cmd = get_word_arr(line);
    if (cmd == NULL)
        return -1;
    remove_commentary(cmd);
    if (cmd[0] == NULL)
        return 0;
    for (int i = 0; i < NB_INSTRUCTIONS; ++i) {
        if (my_strcmp(mnemonique[i], cmd[0]) == 0) {
            nb_bytes = (size_tab[i])(cmd);
            free_tab(cmd);
            return nb_bytes;
        }
    }
    free_tab(cmd);
    my_puterr("error count bytes\n");
    return -1;
}

char *get_label_name(char *line)
{
    char *label_name = malloc(sizeof(char) * my_strlen(line));
    int i = 0;

    if (label_name == NULL)
        return NULL;
    for (i = 0; line[i] != ':'; ++i) {
        label_name[i] = line[i];
    }
    label_name[i] = '\0';
    return label_name;
}

label_t *add_to_label(label_t **labels, char *line, int nb_bytes)
{
    char *label_name = get_label_name(line);

    if (label_name == NULL) {
        my_puterr("malloc error\n");
        return NULL;
    }
    *labels = add_label(labels, label_name, nb_bytes);
    free(label_name);
    if (*labels == NULL) {
        my_puterr("malloc error\n");
        return NULL;
    }
    return *labels;
}

int skip_header(char *line, size_t getline_size, FILE *asm_stream)
{
    for (int i = 0; i < 2; ++i) {
        if (getline(&line, &getline_size, asm_stream) == -1)
            return 84;
        if (line[0] == '#' || line[0] == '\n')
            --i;
    }
    return 0;
}

label_t *get_all_label(FILE *asm_stream)
{
    char *line = NULL;
    size_t getline_size = 0;
    label_t *labels = NULL;
    int nb_bytes = 0;

    labels = add_label(&labels, my_strdup("end"), 0);
    fseek(asm_stream, 0, SEEK_SET);
    if (skip_header(line, getline_size, asm_stream) == 84)
        return NULL;
    while (getline(&line, &getline_size, asm_stream) != -1) {
        if (line[0] == '\n' || line[0] == '\0' || line [0] == '#')
            continue;
        if (is_a_label(line) == 0)
            labels = add_to_label(&labels, line, nb_bytes);
        nb_bytes += count_bytes(line);
    }
    if (line)
        free(line);
    return labels;
}
