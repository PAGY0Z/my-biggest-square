/*
** EPITECH PROJECT, 2022
** B-CPE-110-RUN-1-1-BSQ-pierre-alexandre.grosset
** File description:
** default_func3
*/

#include "biggest_square.h"

int count_backslash(char const *str)
{
    int i = 0;
    int count = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n')
            count++;
        i++;
    }
    return count;
}
