#pragma once

void make_field(
        const int field_size,
        unsigned char field[],
        unsigned char figure[],
        int nlines,
        int ncols);
void init_field(const int field_size, unsigned char field[]);
void put_figure_at_the_center(
        const int field_size,
        unsigned char field[],
        unsigned char figure[],
        int nlines,
        int ncols);
void field_copy(
        const int field_size,
        unsigned char field[],
        unsigned char temp_field[]);
