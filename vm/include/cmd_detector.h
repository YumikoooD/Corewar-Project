/*
** EPITECH PROJECT, 2022
** Minishell1
** File description:
** cmd_detector.h
*/

#include "vm.h"
#include <stdio.h>
#include <string.h>

#ifndef CMD_DETECTOR_H_
    #define CMD_DETECTOR_H_

typedef struct cmd_detector {
    int opcode;
    int (*detect)(vm_t *, fighter_t *);
} cmd_detector_t;

cmd_detector_t command[] = {
    {1, &cmd_live},
    {2, &cmd_ld},
    {3, &cmd_st},
    {4, &cmd_add},
    {5, &cmd_sub},
    {6, &cmd_and},
    {7, &cmd_or},
    {8, &cmd_xor},
    {9, &cmd_zjmp},
    {10, &cmd_ldi},
    {11, &cmd_sti},
    {12, &cmd_fork},
    {13, &cmd_lld},
    {14, &cmd_lldi},
    {15, &cmd_lfork},
    {16, &cmd_aff}
};

#endif /* CMD_DETECTOR_H_ */
