/*
** EPITECH PROJECT, 2023
** utils
** File description:
** maths
*/

#include "my.h"
#include "vm.h"

long absolute(long nb)
{
    if (nb < 0)
        return -nb;
    return nb;
}
