/*
** EPITECH PROJECT, 2022
** B-CPE-110-RUN-1-1-BSQ-pierre-alexandre.grosset
** File description:
** default_func2
*/

#include "biggest_square.h"
#include <stdlib.h>

char *my_strdup(char const *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;
    while (str[i] != '\0') {
        new_str[i] = str[i];
        i++;
    }
    new_str[my_strlen(str)] = '\0';
    return new_str;
}

char **my_str_to_word_array(char const *str)
{
    char *cpy = my_strdup(str);
    if (count_backslash(str) - 1 != my_getnbr(str))
        return NULL;
    char **array = malloc(sizeof(char *) * (my_getnbr(str) + 2));
    char *adress = cpy;
    int size = my_strlen(cpy);
    int y = 0;
    for (int i = 0; i < size; i++) {
        if (cpy[i] == '\n') {
            cpy[i] = '\0';
            array[y] = my_strdup(cpy);
            size = size - i - 1;
            cpy += i + 1;
            i = 0;
            y++;
        }
    }
    array[y] = my_strdup(cpy);
    free(adress);
    return array;
}

int is_strnum(char const *str)
{
    int i = 0;
    while (str[i]) {
        if (str[i] < '0' || '9' < str[i])
            return 0;
        i++;
    }
    return 1;
}

int is_token(char const c, char const *const tokens)
{
    for (int i = 0; tokens[i] != '\0'; i++){
        if (c == tokens[i])
            return 1;
    }
    return 0;
}

int is_validstr(char const *str)
{
    int i = 0;
    while (str[i]) {
        if (is_token(str[i], ".o"))
            i++;
        else
            return 0;
    }
    return 1;
}
