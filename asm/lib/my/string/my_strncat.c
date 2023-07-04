/*
** EPITECH PROJECT, 2022
** strncat
** File description:
** strncat
*/

int my_strlen(char const *str);

unsigned char *my_strncat(unsigned char *dest,
unsigned char *src, int nb, int len)
{
    for (int i = 0; i < nb; ++i) {
        dest[i + len] = src[i];
    }
    return (dest);
}
