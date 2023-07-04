/*
** EPITECH PROJECT, 2023
** cor file
** File description:
** asm corewar
*/

#include "my.h"
#include "asm.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

static char *remove_path(char *filepath)
{
    char *filename = filepath;

    for (int i = 0; filepath[i] != '\0'; ++i) {
        if (filepath[i] == '/') {
            filename = filepath + i + 1;
        }
    }
    return filename;
}

static char *get_cor_filename(char *asm_filename)
{
    const int asm_len = my_strlen(asm_filename);
    const int cor_ext_len = my_strlen(".cor");
    const int asm_ext_len = my_strlen(".s");
    char *filename = malloc(sizeof(char *) * (asm_len + cor_ext_len));

    if (filename == NULL) {
        my_puterr("malloc error\n");
        return NULL;
    }
    asm_filename = remove_path(asm_filename);
    my_strcpy(filename, asm_filename);
    filename[my_strlen(asm_filename) - asm_ext_len] = '\0';
    my_strcat(filename, ".cor");
    return filename;
}

int get_cor_stream(char *asm_filename)
{
    char *cor_filename = get_cor_filename(asm_filename);
    int cor_stream = 0;

    if (cor_filename == NULL)
        return -1;
    cor_stream = open(cor_filename, O_TRUNC | O_CREAT | O_WRONLY, 0666);
    free(cor_filename);
    if (cor_stream == -1) {
        my_puterr("Failed to create .cor file\n");
        return -1;
    }
    return cor_stream;
}

static FILE *get_asm_stream(char *asm_filename)
{
    FILE *asm_stream = fopen(asm_filename, "r");

    if (asm_stream == NULL) {
        my_puterr("Failed to open .s file\n");
        return NULL;
    }
    return asm_stream;
}

int init_streams(stream_t *streams, char *asm_filename)
{
    streams->asm_stream = get_asm_stream(asm_filename);
    if (streams->asm_stream == NULL)
        return 84;
    streams->str_len = 0;
    return 0;
}
