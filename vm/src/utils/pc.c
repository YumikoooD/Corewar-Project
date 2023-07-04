/*
** EPITECH PROJECT, 2022
** utils
** File description:
** pc.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdbool.h>
#include "vm.h"
#include "table.h"
#include "op.h"

void update_pc(fighter_t *fighter, args_type_t *args, int num_args, int ocp)
{
    int add = 1;

    for (int i = 0; i < num_args; i++) {
        add += type_size(args[i]);
    }
    add += ocp;
    normalize_pc(fighter, add);
}

void normalize_pc(fighter_t *fighter, int to_add)
{
    fighter->pc += to_add;
    while (fighter->pc > 65535)
        fighter->pc -= 65536;
    while (fighter->pc < 0)
        fighter->pc += 65536;
}
