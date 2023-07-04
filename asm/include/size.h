/*
** EPITECH PROJECT, 2023
** corewar asm
** File description:
** size header
*/

#ifndef SIZE_H_
    #define SIZE_H_

typedef int (*size_function)(char **);

extern size_function size_tab[];

int get_live_size(char **cmd);
int get_zjmp_size(char **cmd);
int get_aff_size(char **cmd);
int get_fork_size(char **cmd);
int get_ld_size(char **cmd);
int get_st_size(char **cmd);
int get_add_sub_size(char **cmd);
int get_operator_size(char **cmd);
int get_ldi_size(char **cmd);
int get_sti_size(char **cmd);

#endif /* SIZE_H_ */
