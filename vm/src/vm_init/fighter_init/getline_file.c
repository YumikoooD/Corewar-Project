/*
** EPITECH PROJECT, 2022
** vm
** File description:
** getline_file.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include "vm.h"

int get_file_size(char *file)
{
    FILE *fp = fopen(file, "r");
    size_t size = 0;
    char *str = NULL;
    int chars_read;
    int total_chars = 0;

    if (fp == NULL) {
        return ERROR;
    }
    while ((chars_read = getline(&str, &size, fp)) != -1) {
        total_chars += chars_read;
    }
    free(str);
    if (ferror(fp)) {
        return ERROR;
    }
    fclose(fp);
    return total_chars;
}

char *getline_file(char *file)
{
    int sized = get_file_size(file);
    int fd = open(file, O_RDONLY);
    char *buffer = NULL;

    if (fd == -1)
        return NULL;
    buffer = malloc(sizeof(char) * (sized + 1));
    if (buffer == NULL)
        return NULL;
    buffer[sized] = '\0';
    if (read(fd, buffer, sized) != sized)
        return NULL;
    close(fd);
    return buffer;
}
