#pragma once

#include "const.h"

void make_field(
        unsigned char field[FIELD_SIZE][FIELD_SIZE],
        unsigned char figure[],
        int nlines,
        int ncols);
void init_field(unsigned char field[FIELD_SIZE][FIELD_SIZE]);
void put_figure_at_the_center(
        unsigned char field[FIELD_SIZE][FIELD_SIZE],
        unsigned char figure[],
        int nlines,
        int ncols);
