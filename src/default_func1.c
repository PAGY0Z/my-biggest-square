/*
** EPITECH PROJECT, 2022
** B-CPE-110-RUN-1-1-BSQ-pierre-alexandre.grosset
** File description:
** default_func1
*/
#include <stdio.h>

#include <unistd.h>

int my_putchar(char c)
{
    return write(1, &c, 1);
}

int my_strlen(char const *str)
{
    int x = 0;
    while (str[x] != '\0') {
        x++;
    }
    return x;
}

int my_putstr(char const *str)
{
    return write(1, str, my_strlen(str));
}

int min_value(int a, int b, int c)
{
    int min_value = (a > b) ? b : a;
    min_value = (min_value > c) ? c : min_value;
    return min_value;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    long nbr2 = 0;
    while (47 < str[i] && str[i] < 58) {
        nbr = nbr * 10 + (str[i] - 48);
        nbr2 = nbr2 * 10 + (str[i] - 48);
        if (nbr2 > 2147483647)
            return -1;
        i++;
    }
    return nbr;
}
