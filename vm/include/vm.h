/*
** EPITECH PROJECT, 2022
** Minishell1
** File description:
** mysh.h
*/

#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "op.h"

#ifndef VM_H_
    #define VM_H_

    #define ERROR 84
    #define SUCCESS 0

typedef struct fighter_s {

    char *name;
    char *comment;
    char *body;
    int fighter_number;
    int body_size;
    int address;
    int cycle_exec;
    int last_live_call;
    int *reg;
    int pc;
    bool carry;
    bool alive;

} fighter_t;

typedef struct vm_s {

    int dump_nbr_cycle;
    int prog_number;
    int fighter_address;

    fighter_t **fighter;
    int *arena;
    int fighter_nbr;

    int actual_cycle;
    int live_call;
    fighter_t *fighter_alive;

} vm_t;

int asm_fighter(vm_t *data, fighter_t *fighter, char *file);
void destroy(vm_t *data);
int vm_init(vm_t *data, int ac, char **av);
char *getline_file(char *file);
char **get_cor_file(int ac, char **av, vm_t *data);
int get_number_file(int ac, char **av, vm_t *data);
char *reverse_string(unsigned char* buffer, int length);
int reverse_int(unsigned char* buff);
int get_cor(fighter_t *fighter, char *buffer);
void my_memset(int *ptr, int value, int num);
long absolute(long nb);
int place_fighter(vm_t *data);
int load_dump(char *str, vm_t *data);
int load_prog_adress(char *str, vm_t *data);
int load_prog_number(char *str, vm_t *data);
void add_fighter(fighter_t ***fighter, fighter_t *to_add, vm_t *data);
int file_manager(vm_t *data, char *file);
int init_flags(vm_t *data, int ac, char **av);
void show_help(void);
int address_setup(vm_t *data, fighter_t *fighter, int address);
fighter_t *fighter_cpy(fighter_t *fighter, vm_t *data);
int init_arena(vm_t *data);
void init_data(vm_t *data);
void show_help(void);
int error_input(vm_t *data, int ac, char **av);

void sort_fighters_bubble(fighter_t **fighters, int len);
void partition_alive_dead(fighter_t **fighters);
int normalize_adress(fighter_t *fighter, int to_add);
int get_nb_bytes_arg(vm_t *data, int address, int nb);
void update_pc(fighter_t *fighter, args_type_t *args,
int num_args, int ocp);
void normalize_pc(fighter_t *fighter, int to_add);
args_type_t get_argument_type(vm_t *data, int exec_address, int arg);
int get_arg_value_by_type(vm_t *data, args_type_t type,
int address, fighter_t *fighter);
int get_arg_value_by_type_relative(vm_t *data, args_type_t type,
int address, fighter_t *fighter);
int type_size(args_type_t arg_type);
void write_nbytes(vm_t *data, int address, int value, int nb);
void show_win(vm_t *data);
void find_dead_fighters(vm_t *data);
void fighter_fight(vm_t *data);
bool detect_error(vm_t *data, fighter_t *fighter, int opcode);

int cmd_detector(vm_t *data, fighter_t *fighter, int opcode);
int cmd_live(vm_t *data, fighter_t *fighter);
int cmd_zjmp(vm_t *data, fighter_t *fighter);
int cmd_xor(vm_t *data, fighter_t *fighter);
int cmd_sub(vm_t *data, fighter_t *fighter);
int cmd_sti(vm_t *data, fighter_t *fighter);
int cmd_st(vm_t *data, fighter_t *fighter);
int cmd_or(vm_t *data, fighter_t *fighter);
int cmd_lldi(vm_t *data, fighter_t *fighter);
int cmd_lld(vm_t *data, fighter_t *fighter);
int cmd_lfork(vm_t *data, fighter_t *fighter);
int cmd_ldi(vm_t *data, fighter_t *fighter);
int cmd_ld(vm_t *data, fighter_t *fighter);
int cmd_fork(vm_t *data, fighter_t *fighter);
int cmd_and(vm_t *data, fighter_t *fighter);
int cmd_aff(vm_t *data, fighter_t *fighter);
int cmd_add(vm_t *data, fighter_t *fighter);

#endif /* VM_H_ */
