/*
** EPITECH PROJECT, 2022
** vm
** File description:
** reverse.c
*/

#include "my.h"
#include <stdlib.h>
#include "vm.h"

int reverse_int(unsigned char* buff)
{
    int number =
    buff[0] << 24 | buff[1] << 16 |
    buff[2] << 8 | buff[3];

    return number;
}

char *reverse_string(unsigned char* buffer, int length)
{
    char *str = malloc(sizeof(char) * (length + 1));

    my_memcpy(str, buffer, length);
    str[length] = '\0';
    return str;
}
