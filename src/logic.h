#pragma once

#include "const.h"

int get_count_neighbours(
        unsigned char field[FIELD_SIZE][FIELD_SIZE], int i, int j);
int life_or_death(unsigned char cell, int neighbour_cell_count);
