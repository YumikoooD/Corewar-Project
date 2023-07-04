/*
** EPITECH PROJECT, 2022
** C-Library
** File description:
** string_to_int.c
*/

#include "../my.h"

int my_atoi(char *str)
{
    int res = 0;
    int is_neg = 0;

    if (str[0] == '-') {
        is_neg = 1;
        ++str;
    }
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] < '0' || str[i] > '9')
            return LEN_ERROR;
    }
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    if (is_neg == 1)
        --str;
    if (str[0] == '-')
        res *= -1;
    return res;
}
