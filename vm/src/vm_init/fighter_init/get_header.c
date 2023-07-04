/*
** EPITECH PROJECT, 2022
** vm
** File description:
** get_header.c
*/

#include "my.h"
#include <stdlib.h>
#include "vm.h"
#include "op.h"

int get_name(fighter_t *fighter, char *buffer)
{
    int max_length = 4 + PROG_NAME_LENGTH;

    for (int i = 4; i < max_length; i++) {
        fighter->name[i - 4] = buffer[i];
    }
    fighter->name[PROG_NAME_LENGTH] = '\0';
    return SUCCESS;
}

int get_comment(fighter_t *fighter, char *buffer)
{
    int max_length = 12 + PROG_NAME_LENGTH + COMMENT_LENGTH;
    int decal_length = 0;

    for (int i = 12 + PROG_NAME_LENGTH; i < max_length; i++) {
        decal_length = i - 12 - PROG_NAME_LENGTH;
        fighter->comment[decal_length] = buffer[i];
    }
    fighter->comment[COMMENT_LENGTH] = '\0';
    return SUCCESS;
}

int get_body_size(fighter_t *fighter, char *buffer)
{
    fighter->body_size = buffer[4 + PROG_NAME_LENGTH];
    for (int i = 5 + PROG_NAME_LENGTH; i < 12 + PROG_NAME_LENGTH; i++) {
        fighter->body_size = fighter->body_size << 8;
        fighter->body_size += buffer[i];
    }
    return SUCCESS;
}

int get_body(fighter_t *fighter, char *buffer)
{
    int body_start = 12 + PROG_NAME_LENGTH + COMMENT_LENGTH;

    get_body_size(fighter, buffer);
    fighter->body = malloc(sizeof(char) * (fighter->body_size));
    if (fighter->body == NULL)
        return ERROR;
    for (int i = body_start; i < body_start + fighter->body_size; i++) {
        fighter->body[i - body_start] = buffer[i + 4];
    }
    return SUCCESS;
}

int get_cor(fighter_t *fighter, char *buffer)
{
    fighter->name = malloc(sizeof(char) * (PROG_NAME_LENGTH + 1));
    fighter->comment = malloc(sizeof(char) * (COMMENT_LENGTH + 1));
    if (fighter->name == NULL || fighter->comment == NULL)
        return ERROR;
    get_name(fighter, buffer);
    get_comment(fighter, buffer);
    get_body(fighter, buffer);
    return SUCCESS;
}
