/*
** EPITECH PROJECT, 2023
** header
** File description:
** asm body
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../my.h"

unsigned char convert_to_hex(char *hexa)
{
    unsigned char value = 0;
    size_t length = my_strlen(hexa);

    for (size_t i = 0; i < length; i++) {
        value = (value << 4) + (hexa[i] - '0');
    }
    return value;
}
