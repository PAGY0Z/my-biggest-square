/*
** EPITECH PROJECT, 2022
** B-CPE-110-RUN-1-1-BSQ-pierre-alexandre.grosset
** File description:
** bsq_map_checker
*/

#include "biggest_square.h"

int map_check_size(char **map, int size)
{
    int x = 0;
    while (map[x][0] != '\0') {
        x++;
    }
    if (x != size + 1) {
        return 84;
    }
    return 0;
}

int map_check_linesize(char **map)
{
    int x = 1;
    while (map[x][0] != '\0') {
        if (my_strlen(map[x]) != my_strlen(map[1])) {
            return 84;
        }
        x++;
    }
    return 0;
}

int map_check_char(char **map)
{
    for (int x = 1; map[x][0] != '\0'; x++) {
        if (!(is_validstr(map[x]))) {
            return 84;
        }
    }
    return 0;
}

int map_validity(char **map, int size)
{
    int value = map_check_size(map, size);
    value = (value == 0) ? map_check_linesize(map) : value;
    value = (value == 0) ? map_check_char(map) : value;
    return value;
}
