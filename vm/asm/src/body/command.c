/*
** EPITECH PROJECT, 2023
** header
** File description:
** asm body
*/

#include <stdio.h>
#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my.h"
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "op.h"

int check_command(char *line, stream_t *streams)
{
    char **tab = get_word_arr(line);

    if (tab == NULL)
        return 84;
    remove_commentary(tab);
    if (tab[0] == NULL) {
        free_tab(tab);
        return 0;
    }
    for (int i = 0; i < NB_INSTRUCTIONS; i++) {
        call_function(tab, i, streams, line);
    }
    free_tab(tab);
    return 0;
}

void call_function(char **tab, int i, stream_t *streams, char *line)
{
    unsigned char temp[1];

    for (int j = 0; tab[j] != NULL; j++) {
        if (my_strcmp(tab[j], mnemonique[i]) == 0) {
            temp[0] = code[i];
            my_strncat(streams->str, temp, 1, streams->str_len);
            streams->str_len += 1;
            coding_byte(line, streams);
        }
    }
}

int coding_byte(char *line, stream_t *streams)
{
    char **tab = get_word_arr(line);
    char *bin = malloc(sizeof(char) * 8 + 1);
    unsigned char value[1];

    if (bin == NULL || tab == NULL)
        return 84;
    remove_commentary(tab);
    for (int i = 0; i < 8; ++i)
        bin[i] = '0';
    if (!(my_arrlen(tab) < 3 && my_strcmp(tab[0], "aff") != 0)) {
        value[0] = get_hexa_args(tab, bin);
        my_strncat(streams->str, value, 1, streams->str_len);
        streams->str_len += 1;
    }
    free(bin);
    free_tab(tab);
    return 0;
}

unsigned char get_hexa_args(char **tab, char *bin)
{
    int j = 0;
    unsigned short value = 0;

    for (int i = 1; tab[i] != NULL; i++) {
        bin = complete_bin(tab, bin, i, j);
        j += 2;
    }
    bin[8] = '\0';
    value = get_binary_value(bin);
    return value;
}

char *complete_bin(char **tab, char bin[], int i, int j)
{
    if (tab[i][0] == 'r') {
        bin[j] = '0';
        bin[j + 1] = '1';
    } else if (tab[i][0] == '%') {
        bin[j] = '1';
        bin[j + 1] = '0';
    } else {
        bin[j] = '1';
        bin[j + 1] = '1';
    }
    return bin;
}
