#include "field.h"

void make_field(
        const int field_size,
        unsigned char field[],
        unsigned char figure[],
        int nlines,
        int ncols)
{
    /*Создаем поле для игры*/
    init_field(field_size, field);
    put_figure_at_the_center(field_size, field, figure, nlines, ncols);
}

void init_field(const int field_size, unsigned char field[])
{
    /*Инициализация поля*/
    for (int i = 0; i < field_size; i++) {
        for (int j = 0; j < field_size; j++) {
            field[i * field_size + j] = 0;
        }
    }
}

void put_figure_at_the_center(
        const int field_size,
        unsigned char field[],
        unsigned char figure[],
        int nlines,
        int ncols)
{
    /*Помещаем фигуру в центр поля*/
    int i = (field_size - nlines) / 2;
    int j;
    for (int k = 0; k < nlines; i++, k++) {
        j = (field_size - ncols) / 2;
        for (int l = 0; l < ncols; j++, l++) {
            field[i * field_size + j] = figure[k * ncols + l];
        }
    }
}

void field_copy(
        const int field_size, unsigned char field[], unsigned char temp_field[])
{
    /*Копируем поле*/
    for (int i = 0; i < field_size; i++) {
        for (int j = 0; j < field_size; j++) {
            temp_field[i * field_size + j] = field[i * field_size + j];
        }
    }
}
