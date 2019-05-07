#include "field.h"

void make_field(
        unsigned char field[FIELD_SIZE][FIELD_SIZE],
        unsigned char figure[],
        int nlines,
        int ncols)
{
    /*Создаем поле для игры*/
    init_field(field);
    put_figure_at_the_center(field, figure, nlines, ncols);
}

void init_field(unsigned char field[FIELD_SIZE][FIELD_SIZE])
{
    /*Инициализация поля*/
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            field[i][j] = 0;
        }
    }
}

void put_figure_at_the_center(
        unsigned char field[FIELD_SIZE][FIELD_SIZE],
        unsigned char figure[],
        int nlines,
        int ncols)
{
    /*Помещаем фигуру в центр поля*/
    int i = (FIELD_SIZE - nlines) / 2;
    int j;
    for (int k = 0; k < nlines; i++, k++) {
        j = (FIELD_SIZE - ncols) / 2;
        for (int l = 0; l < ncols; j++, l++) {
            field[i][j] = figure[k * ncols + l];
        }
    }
}

void field_copy(
        unsigned char field[FIELD_SIZE][FIELD_SIZE],
        unsigned char temp_field[FIELD_SIZE][FIELD_SIZE])
{
    /*Копируем поле*/
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            temp_field[i][j] = field[i][j];
        }
    }
}
