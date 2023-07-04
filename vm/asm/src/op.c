/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** asm corewar
*/

#include "op.h"
#include "error_handling.h"
#include "size.h"

op_t    op_tab[] =
{
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
    "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
    "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
    "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
    "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
    "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
    "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
};

check_function check_tab[] = {check_live, check_ld, check_st, check_add_sub,
    check_add_sub, check_operator, check_operator, check_operator,
    check_zjmp, check_ldi, check_sti, check_fork, check_ld,
    check_ldi, check_fork, check_aff};

char *mnemonique[] = {"live", "ld", "st", "add",
    "sub", "and", "or", "xor",
    "zjmp", "ldi", "sti", "fork", "lld",
    "lldi", "lfork", "aff"};

unsigned char code[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
    0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10};

size_function size_tab[] = {get_live_size, get_ld_size,
    get_st_size, get_add_sub_size,
    get_add_sub_size, get_operator_size, get_operator_size, get_operator_size,
    get_zjmp_size, get_ldi_size, get_sti_size, get_fork_size, get_ld_size,
    get_ldi_size, get_fork_size, get_aff_size};

char *index_cmd[] = {"zjmp", "ldi", "lldi", "sti", "fork", "lfork"};
