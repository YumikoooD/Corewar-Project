/*
** EPITECH PROJECT, 2023
** lib
** File description:
** word array
*/

#include <stdlib.h>

static size_t get_word_len(char *str, int i)
{
    int len = 0;

    for (; str[i + len] != '\n' && str[i + len] != '\0' &&
            str[i + len] != ' ' && str[i + len] != ',' &&
            str[i + len] != '\t'; ++len);
    return len;
}

static char *get_word(char *str, size_t *i)
{
    size_t len = get_word_len(str, *i);
    char *word = NULL;
    size_t start = *i;
    int j = 0;

    if (len == 0)
        return NULL;
    word = malloc(sizeof(char) * len + 1);
    if (word == NULL)
        return NULL;
    for (j = 0; *i < start + len; ++*i, ++j)
        word[j] = str[*i];
    word[j] = '\0';
    return word;
}

static int get_is_word(char *str, size_t *i)
{
    int len = get_word_len(str, *i);
    size_t start = *i;

    for (; *i < start + len; ++*i);
    if (str[*i] != '\0')
        ++*i;
    return (len == 0) ? 0 : 1;
}

static void fill_all_word(char **all_word, char *str, int nb_word)
{
    int j = 0;
    size_t i = 0;
    char *word = NULL;

    while (str[i] != '\0') {
        word = get_word(str, &i);
        if (word != NULL) {
            all_word[j] = word;
            ++j;
        } else
            ++i;
    }
    all_word[nb_word] = NULL;
}

char **get_word_arr(char *str)
{
    int nb_word = 0;
    size_t i = 0;
    char **all_word = NULL;

    while (str[i] != '\0')
        nb_word += get_is_word(str, &i);
    all_word = malloc(sizeof(char *) * (nb_word + 1));
    if (all_word == NULL)
        return NULL;
    fill_all_word(all_word, str, nb_word);
    return all_word;
}
