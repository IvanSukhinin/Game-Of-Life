#include <stdio.h>

#define FIELD_SIZE 20

unsigned char tumbler[6][7] = {
        {0, 1, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1},
        {1, 1, 0, 0, 0, 1, 1},
};

void make_figure(
        unsigned char field[FIELD_SIZE][FIELD_SIZE],
        unsigned char figure[],
        int nlines,
        int ncols);
void print_field(unsigned char field[FIELD_SIZE][FIELD_SIZE]);
void init_field(unsigned char field[FIELD_SIZE][FIELD_SIZE]);

int main()
{
    unsigned char field[FIELD_SIZE][FIELD_SIZE];

    init_field(field);
    make_figure(field, &tumbler[0][0], 6, 7);
    print_field(field);

    return 0;
}

void print_field(unsigned char field[FIELD_SIZE][FIELD_SIZE])
{
    /*Вывод поля*/
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            if (field[i][j] == 0) {
                printf("# ");
            } else if (field[i][j] == 1) {
                printf("! ");
            }
        }
        printf("\n");
    }
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

void make_figure(
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
