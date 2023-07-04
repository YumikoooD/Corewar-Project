/*
** EPITECH PROJECT, 2022
** vm
** File description:
** my_memset.c
*/

#include "my.h"
#include "vm.h"
#include <stddef.h>

void my_memset(int *ptr, int value, int num)
{
    for (int i = 0; i < num; i++)
        ptr[i] = value;
}
