/*
** EPITECH PROJECT, 2022
** B-CPE-110-RUN-1-1-BSQ-pierre-alexandre.grosset
** File description:
** bsq_struct_update
*/

#include "biggest_square.h"

void st_value_update(int **v, int x, int y, values_struct_t *values)
{
    values->v1 = (x > 0 && y > 0) ? v[x - 1][y] : 0;
    values->v2 = (x > 0 && y > 0) ? v[x][y - 1] : 0;
    values->v3 = (x > 0 && y > 0) ? v[x - 1][y - 1] : 0;
}

void st_bsqi_update(int **v, int x, int y, biggest_square_t *bsq_i)
{
    bsq_i->coord_x = (v[x][y] > bsq_i->bsq_v) ? x : bsq_i->coord_x;
    bsq_i->coord_y = (v[x][y] > bsq_i->bsq_v) ? y : bsq_i->coord_y;
    bsq_i->bsq_v = (v[x][y] > bsq_i->bsq_v) ? v[x][y] : bsq_i->bsq_v;
}
