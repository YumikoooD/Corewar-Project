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

int write_reg(char *reg, stream_t *streams)
{
    unsigned char reg_nb[1];
    unsigned char *str = streams->str;

    ++reg;
    reg_nb[0] = my_atoi(reg);
    my_strncat(str, reg_nb, 1, streams->str_len);
    streams->str_len += 1;
    return 0;
}

int write_label(char *label, stream_t *streams, label_t *labels, int nb_bytes)
{
    int address = get_label_address(labels, label);
    unsigned char buffer[4];
    unsigned char *str = streams->str;

    if (address == -1)
        return 84;
    address = address - nb_bytes;
    buffer[0] = (address >> 24) & 0xFF;
    buffer[1] = (address >> 16) & 0xFF;
    buffer[2] = (address >> 8) & 0xFF;
    buffer[3] = address & 0xFF;
    my_strncat(str, buffer, 4, streams->str_len);
    streams->str_len += 4;
    return 0;
}

int write_ind(char *ind, stream_t *streams, label_t *labels, int nb_bytes)
{
    unsigned char buffer[2];
    int ind_value = 0;
    unsigned char *str = streams->str;

    if (ind[0] == ':')
        return write_index_label(ind + 1, streams, labels, nb_bytes);
    ind_value = my_atoi(ind);
    buffer[0] = (ind_value >> 8) & 0xFF;
    buffer[1] = ind_value & 0xFF;
    my_strncat(str, buffer, 2, streams->str_len);
    streams->str_len += 2;
    return 0;
}

int write_dir(char *dir, stream_t *streams, label_t *labels, int nb_bytes)
{
    unsigned char buffer[4];
    int dir_value = 0;
    unsigned char *str = streams->str;

    if (dir[1] == LABEL_CHAR)
        return write_label(dir + 2, streams, labels, nb_bytes);
    ++dir;
    dir_value = my_atoi(dir);
    buffer[0] = (dir_value >> 24) & 0xFF;
    buffer[1] = (dir_value >> 16) & 0xFF;
    buffer[2] = (dir_value >> 8) & 0xFF;
    buffer[3] = dir_value & 0xFF;
    my_strncat(str, buffer, 4, streams->str_len);
    streams->str_len += 4;
    return 0;
}
