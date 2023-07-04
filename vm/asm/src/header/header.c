/*
** EPITECH PROJECT, 2023
** header
** File description:
** asm header
*/

#include <stdio.h>
#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my.h"
#include <unistd.h>

static int check_valid_line(char *line, char *type)
{
    while (*line == '\t' || *line == ' ')
        ++line;
    if (my_strncmp(line, type, my_strlen(type)) != 0)
        return 84;
    line += my_strlen(type);
    while (*line == ' ' || *line == '\t')
        line += 1;
    if (*line != '\"')
        return 84;
    for (; *line != '\"' && *line != '\0'
        && *line != '\n'; ++line);
    if (*line != '\"')
        return 84;
    if (line[my_strlen(line) - 2] != '\"' &&
        line[my_strlen(line) - 2] != '\t' &&
        line[my_strlen(line) - 2] != ' ')
        return 84;
    return 0;
}

static void copy_info(char *info, char *line, char *type)
{
    while (*line == '\t' || *line == ' ')
        ++line;
    line += my_strlen(type);
    for (; *line == ' ' || *line == '\t' ||
            *line == '\"'; ++line);
    my_strcpy(info, line);
}

static char *get_info(FILE *asm_stream, char *type, char info[], int size)
{
    char *line = NULL;
    size_t getline_size = 0;

    if (getline(&line, &getline_size, asm_stream) == -1)
        return NULL;
    if (line[0] == '#' || line[0] == '\n') {
        return get_info(asm_stream, type, info, size);
    }
    if (check_valid_line(line, type) == 84) {
        my_puterr("Error in header\n");
        free(line);
        return NULL;
    }
    copy_info(info, line, type);
    free(line);
    for (int i = my_strlen(info) - 2; i <= size + 3; ++i) {
        info[i] = '\0';
    }
    return info;
}

static int get_program_size(FILE *asm_stream)
{
    int program_size = 0;
    char *line = NULL;
    size_t getline_size = 0;

    fseek(asm_stream, 0, SEEK_SET);
    for (int i = 0; i < 2; ++i) {
        if (getline(&line, &getline_size, asm_stream) == -1)
            return -1;
        if (line[0] == '#' || line[0] == '\n')
            --i;
    }
    while (getline(&line, &getline_size, asm_stream) != -1) {
        if (line[0] != '\0' && line[0] != '\n' && line[0] != '#') {
            program_size += count_bytes(line);
        }
    }
    free(line);
    return program_size;
}

header_t *get_header(stream_t *streams)
{
    header_t *header = malloc(sizeof(header_t));

    fseek(streams->asm_stream, 0, SEEK_SET);
    header->magic = COREWAR_EXEC_MAGIC;
    if (get_info(streams->asm_stream, NAME_CMD_STRING,
                header->prog_name, PROG_NAME_LENGTH) == NULL)
        return NULL;
    if (get_info(streams->asm_stream, COMMENT_CMD_STRING,
                header->comment, COMMENT_LENGTH) == NULL)
        return NULL;
    header->prog_size = get_program_size(streams->asm_stream);
    streams->str = malloc(sizeof(unsigned char) * header->prog_size + 1);
    return header;
}
