/*
** EPITECH PROJECT, 2022
** vm
** File description:
** show_help.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "op.h"

void show_help(void)
{
    my_printf("USAGE\n\t./corewar [-dump nbr_cycle] [[-n prog_number]");
    my_printf(" [-a load_address] prog_name] ...\nDESCRIPTION\n\t-dump");
    my_printf(" nbr_cycle dumps the memory after the nbr_cycle execution ");
    my_printf("(if the round isn`t already over) with the following format: ");
    my_printf("32 bytes/line in hexadecimal (A0BCDEFE1DD3...)\n\t-n ");
    my_printf("prog_number sets the next program`s number. By default, the ");
    my_printf("first free number in the parameter order\n\t-a load_address ");
    my_printf("sets the next program`s loading address. When no address is ");
    my_printf("specified, optimize the addresses so that the processes ");
    my_printf("are as far away from each other as possible. ");
    my_printf("The addresses are MEM_SIZE modulo.\n");
}
