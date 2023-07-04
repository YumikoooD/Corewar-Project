/*
** EPITECH PROJECT, 2023
** corewar asm
** File description:
** write params
*/

#include "asm.h"
#include <stdio.h>
#include "op.h"
#include <stdlib.h>
#include "my.h"
#include "error_handling.h"
#include <unistd.h>

int write_index_label(char *label, stream_t *streams,
    label_t *labels, int nb_bytes)
{
    int address = get_label_address(labels, label);
    unsigned char buffer[2];
    unsigned char *str = streams->str;

    if (address == -1)
        return 84;
    address = address - nb_bytes;
    buffer[0] = (address >> 8) & 0xFF;
    buffer[1] = address & 0xFF;
    my_strncat(str, buffer, 2, streams->str_len);
    streams->str_len += 2;
    return 0;
}

int write_index(char *ind, stream_t *streams, label_t *labels, int nb_bytes)
{
    unsigned char buffer[2];
    int ind_value = 0;
    unsigned char *str = streams->str;

    if (ind[0] == 'r')
        return write_reg(ind, streams);
    if (ind[1] == LABEL_CHAR)
        return write_index_label(ind + 2, streams, labels, nb_bytes);
    if (ind[0] == DIRECT_CHAR)
        ++ind;
    ind_value = my_atoi(ind);
    buffer[0] = (ind_value >> 8) & 0xFF;
    buffer[1] = ind_value & 0xFF;
    my_strncat(str, buffer, 2, streams->str_len);
    streams->str_len += 2;
    return 0;
}
