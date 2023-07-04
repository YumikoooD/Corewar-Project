/*
** EPITECH PROJECT, 2023
** error handlng header
** File description:
** asm corewar
*/

#ifndef ERROR_HANDLING_H_
    #define ERROR_HANDLING_H_
    #include "asm.h"

typedef int (*check_function)(char **);

extern check_function check_tab[];

int check_live(char **cmd);
int check_zjmp(char **cmd);
int check_aff(char **cmd);
int check_fork(char **cmd);
int check_ld(char **cmd);
int check_st(char **cmd);
int check_add_sub(char **cmd);
int check_operator(char **cmd);
int check_ldi(char **cmd);
int check_sti(char **cmd);

#endif /* ERROR_HANDLING_H_ */
