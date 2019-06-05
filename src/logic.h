#pragma once

void main_logic(const int field_size, unsigned char field[]);
int get_count_neighbours(
        const int field_size, unsigned char field[], int i, int j);
int life_or_death(unsigned char cell, int neighbour_cell_count);
