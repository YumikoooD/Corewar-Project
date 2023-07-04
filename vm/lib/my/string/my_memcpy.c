/*
** EPITECH PROJECT, 2022
** step1
** File description:
** my_memcpy.c
*/

#include "../my.h"

void my_memcpy(void *dest, const void *src, int n)
{
    char *dest_ptr = dest;
    const char* src_ptr = (const char*) src;

    for (int i = 0; i < n; i++) {
        dest_ptr[i] = src_ptr[i];
    }
}
