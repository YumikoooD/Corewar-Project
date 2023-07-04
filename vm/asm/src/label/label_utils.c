/*
** EPITECH PROJECT, 2023
** corewar asm
** File description:
** label utils
*/

#include "asm.h"
#include "my.h"
#include "op.h"
#include <stdlib.h>

label_t *add_label(label_t **head, char *name, int address)
{
    label_t *new = malloc(sizeof(label_t));

    if (new == NULL)
        return NULL;
    new->name = my_strdup(name);
    if (new->name == NULL) {
        free(new);
        return NULL;
    }
    new->address = address;
    new->next = NULL;
    if (*head == NULL)
        *head = new;
    else {
        new->next = *head;
        *head = new;
    }
    return *head;
}

int get_label_address(label_t *head, char *name)
{
    label_t *temp = head;

    while (temp != NULL) {
        if (my_strcmp(temp->name, name) == 0) {
            return temp->address;
        }
        temp = temp->next;
    }
    my_puterr(name);
    my_puterr(": Label not found\n");
    return -1;
}

int is_a_label(char *line)
{
    for (int i = 0; line[i] != ' ' && line[i] != '\t' &&
            line[i] != '\n' && line[i] != '\0'; ++i) {
        if (line[i] == LABEL_CHAR) {
            return 0;
        }
    }
    return -1;
}

void free_label(label_t **head)
{
    label_t *temp = *head;
    label_t *to_free = NULL;

    while (temp != NULL) {
        free(temp->name);
        to_free = temp;
        temp = temp->next;
        free(to_free);
    }
}
