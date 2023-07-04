/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** my_putstr function
*/

#include <unistd.h>

int my_strlen(const char *str);

void my_puterr(char *str)
{
    int length = my_strlen(str);

    write(2, str, length);
}

int my_putstr(char *str)
{
    int length = my_strlen(str);

    write(1, str, length);
    return 0;
}
