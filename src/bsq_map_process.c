/*
** EPITECH PROJECT, 2022
** biggest square
** File description:
** bs_indicators
*/

#include "biggest_square.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void map_display(int **v, biggest_square_t bsq_i, int x, char **map)
{
    for (int y = 0; map[x][y]; y++) {
        if (v[x][y] == 0 && !(range_ofy(y, bsq_i)))
            write(1, "o", 1);
        if (!(v[x][y] == 0) && range_ofy(y, bsq_i))
            write(1, "x", 1);
        if (!(v[x][y] == 0) && !(range_ofy(y, bsq_i)))
            write(1, ".", 1);
    }
}

void map_loop(char **map, int **v, biggest_square_t bsq_i, map_size_t map_size)
{
    int bool1;
    for (int x = 1; x <= map_size.size_x; x++) {
        bool1 = range_ofx(x, bsq_i);
        if (!(bool1))
            write(1, map[x], my_strlen(map[x]));
        else
            map_display(v, bsq_i, x, map);
        write(1, "\n", 1);
    }
}

int indicator_append(char **map, values_struct_t *values, int x, int y)
{
    int pos_value;
    if (x > 1 && y > 0 && map[x][y] == '.') {
        pos_value = min_value(values->v1, values->v2, values->v3) + 1;
    } else if (x > 0 && map[x][y] == 'o') {
        pos_value = 0;
    } else {
        pos_value = 1;
    }
    return pos_value;
}

int bsq(char **map)
{
    values_struct_t values = {0};
    biggest_square_t bsq_i = {0, 0, 1};
    map_size_t map_size = {0};
    map_size.size_x = my_getnbr(map[0]);
    map_size.size_y = my_strlen(map[1]);
    int **v = malloc(sizeof(int *) * (map_size.size_x + 1));
    for (int x = 0; x <= map_size.size_x; x++) {
        v[x] = malloc(sizeof(int) * map_size.size_y);
        for (int y = 0; y < map_size.size_y; y++) {
            st_value_update(v, x, y, &values);
            v[x][y] = indicator_append(map, &values, x, y);
            st_bsqi_update(v, x, y, &bsq_i);
        }
    }
    map_loop(map, v, bsq_i, map_size);
    for (int z = 0; z <= map_size.size_x; z++) {
        free(v[z]);
    }
    free(v);
    return 0;
}
