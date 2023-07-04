/*
** EPITECH PROJECT, 2023
** header
** File description:
** asm corewar
*/

#ifndef COREWAR_ASM_H_
    #define COREWAR_ASM_H_
    #include <stdio.h>
    #include "op.h"

typedef struct stream_s {
    int cor_stream;
    FILE *asm_stream;
    unsigned char *str;
    int str_len;
} stream_t;

typedef struct label {
    char *name;
    int address;
    struct label *next;
} label_t;

typedef struct command {
    char *mnemonic;
    int opcode;
} command_t;

extern char *mnemonique[];
extern unsigned char code[];
extern char *index_cmd[];

int run_asm(stream_t *streams);

int error_handling(int ac, char **av);
int verif_line(char *line);
int verif_file(FILE *asm_stream);
int get_cor_stream(char *asm_filename);
void remove_commentary(char **cmd);
char *skip_label(char *line);

int init_streams(stream_t *streams, char *asm_filename);
header_t *get_header(stream_t *streams);
void write_value(int value, int fd);
int write_line(char *line, stream_t *streams, label_t *labels, int nb_bytes);
int count_bytes(char *line);

int is_a_register(char *param);

label_t *add_label(label_t **head, char *name, int address);
int get_label_address(label_t *head, char *name);
int is_a_label(char *line);
void free_label(label_t **head);

int get_param_size(char *param);

label_t *get_all_label(FILE *asm_stream);
label_t *add_label(label_t **head, char *name, int address);
int is_a_label(char *line);

int write_reg(char *reg, stream_t *streams);
int write_ind(char *ind, stream_t *streams, label_t *labels, int nb_bytes);
int write_dir(char *dir, stream_t *streams, label_t *labels, int nb_bytes);
int write_index_label(char *label, stream_t *streams,
label_t *labels, int nb_bytes);
int write_index(char *ind, stream_t *streams, label_t *labels, int nb_bytes);

int check_command(char *line, stream_t *streams);
int coding_byte(char *line, stream_t *streams);
char *complete_bin(char **tab, char bin[], int i, int j);
unsigned char get_hexa_args(char **tab, char *bin);
void call_function(char **tab, int i, stream_t *streams, char *line);

#endif /* COREWAR_ASM_H_ */
