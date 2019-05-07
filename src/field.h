#pragma once

#include "const.h"

void init_field(unsigned char field[FIELD_SIZE][FIELD_SIZE]);
void make_figure(
        unsigned char field[FIELD_SIZE][FIELD_SIZE],
        unsigned char figure[],
        int nlines,
        int ncols);
