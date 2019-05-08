#pragma once

#include "const.h"

void game_of_life(
        unsigned char field[FIELD_SIZE][FIELD_SIZE],
        unsigned char figure[],
        int nlines,
        int ncols);
int input(unsigned char** figure, int* nlines, int* nrows);