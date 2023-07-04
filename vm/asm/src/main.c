/*
** EPITECH PROJECT, 2022
** src
** File description:
** main.c
*/

#include "my.h"
#include "asm.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_help(void)
{
    my_printf("USAGE\n"
    "./asm file_name[.s]\n"
    "DESCRIPTION\n"
    "USAGE\n"
    "./asm file_name[.s]\n"
    "DESCRIPTION\n"
    "file_name file in assembly language to be converted into 'file_name.cor',"
    " an executable in the Virtual Machine.\n");
}

int setup_asm(stream_t *streams, char **av)
{
    if (init_streams(streams, av[1]) == 84)
        return 84;
    if (verif_file(streams->asm_stream) == 84)
        return 84;
    return 0;
}

int to_big_endian(int num)
{
    int big_endian_num = ((num >> 24) & 0xFF) |
        ((num >> 8) & 0xFF00) |
        ((num << 8) & 0xFF0000) |
        ((num << 24) & 0xFF000000);

    return big_endian_num;
}

int write_in_cor(stream_t *streams, header_t *header, char *asm_filename)
{
    int cor_stream = get_cor_stream(asm_filename);

    if (cor_stream == -1)
        return 84;
    header->magic = to_big_endian(header->magic);
    header->prog_size = to_big_endian(header->prog_size);
    write(cor_stream, header, sizeof(header_t));
    write(cor_stream, streams->str, streams->str_len);
    close(cor_stream);
    free(header);
    free(streams->str);
    return 0;
}

int main(int ac, char **av)
{
    stream_t streams;
    header_t *header = NULL;

    if (error_handling(ac, av) == 84)
        return 84;
    if (my_strcmp(av[1], "-h") == 0) {
        print_help();
        return 0;
    }
    if (setup_asm(&streams, av) == 84)
        return 84;
    if ((header = get_header(&streams)) == NULL)
        return 84;
    if (run_asm(&streams) == 84)
        return 84;
    if (write_in_cor(&streams, header, av[1]) == 84)
        return 84;
    fclose(streams.asm_stream);
}
