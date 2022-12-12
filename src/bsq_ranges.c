/*
** EPITECH PROJECT, 2022
** biggest square
** File description:
** fonctions2
*/

#include "biggest_square.h"

int range_ofx(int x, biggest_square_t bsq_i)
{
    if (bsq_i.coord_x - (bsq_i.bsq_v - 1) <= x && x <= bsq_i.coord_x)
        return 1;
    return 0;
}

int range_ofy(int y, biggest_square_t bsq_i)
{
    if (bsq_i.coord_y - (bsq_i.bsq_v - 1) <= y && y <= bsq_i.coord_y)
        return 1;
    return 0;
}
