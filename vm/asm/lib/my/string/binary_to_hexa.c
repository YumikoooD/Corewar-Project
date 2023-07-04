/*
** EPITECH PROJECT, 2023
** header
** File description:
** asm body
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../my.h"

unsigned char get_binary_value(char *str)
{
    int value = 0;
    int power = 1;

    for (int i = 7; i >= 0; --i) {
        if (str[i] == '1')
            value += power;
        power = power * 2;
    }
    return value;
}
