/*
** EPITECH PROJECT, 2023
** corewar asm
** File description:
** write header
*/

#include <unistd.h>

void write_value(int value, int fd)
{
    unsigned char buffer[4];

    buffer[0] = (value >> 24) & 0xFF;
    buffer[1] = (value >> 16) & 0xFF;
    buffer[2] = (value >> 8) & 0xFF;
    buffer[3] = value & 0xFF;
    write(fd, buffer, 4);
}
