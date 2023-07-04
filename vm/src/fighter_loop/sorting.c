/*
** EPITECH PROJECT, 2022
** src
** File description:
** sorting.c
*/

#include "my.h"
#include <stdlib.h>
#include "op.h"
#include "vm.h"

void partition_alive_dead(fighter_t **fighters)
{
    fighter_t *tmp = NULL;
    int i = 0;
    int j = 0;

    while (fighters[j] != NULL) {
        if (fighters[j]->alive) {
            tmp = fighters[i];
            fighters[i] = fighters[j];
            fighters[j] = tmp;
            i++;
        }
        j++;
    }
}

void swap_fighters(fighter_t **fighters, int j)
{
    fighter_t *temp = NULL;

    if (fighters[j]->fighter_number > fighters[j + 1]->fighter_number) {
        temp = fighters[j];
        fighters[j] = fighters[j + 1];
        fighters[j + 1] = temp;
    }
}

void sort_fighters_bubble(fighter_t **fighters, int len)
{
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            swap_fighters(fighters, j);
        }
    }
}
