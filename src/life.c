#include "life.h"
#include "field.h"
#include "field_print.h"
#include "figures.h"
#include "logic.h"

#include <stdio.h>
#include <unistd.h>

void game_of_life(
        unsigned char field[FIELD_SIZE][FIELD_SIZE],
        unsigned char figure[],
        int nlines,
        int ncols)
{
    unsigned char temp_field[FIELD_SIZE][FIELD_SIZE];

    make_field(field, figure, nlines, ncols);

    while (1) {
        clear_screen();
        printf("Press ctrl + c to exit\n");
        print_field(field);
        usleep(75000);

        field_copy(field, temp_field);

        int neighbour_cell_count;
        int cell_life;

        for (int i = 1; i < FIELD_SIZE - 1; i++) {
            for (int j = 1; j < FIELD_SIZE - 1; j++) {
                neighbour_cell_count = get_count_neighbours(temp_field, i, j);
                cell_life
                        = life_or_death(temp_field[i][j], neighbour_cell_count);
                if (cell_life == 1) {
                    field[i][j] = 1;
                } else if (cell_life == 0) {
                    field[i][j] = 0;
                }
            }
            printf("\n");
        }
    }
}

int input(unsigned char** figure, int* nlines, int* nrows)
{
    int choose;
    printf("1 - Tumbler, 2 - Glider, 3 - Oscillator, 4 - Pentapolem, 5 - "
           "Tennis match, 6 - Spacehsip, 7 - Dragonfly, 8 - Gun\n");
    printf("Your choose : ");
    scanf("%d", &choose);
    switch (choose) {
    case 1:
        *figure = &tumbler[0][0];
        *nlines = 6;
        *nrows = 7;
        return 0;
    case 2:
        *figure = &glider[0][0];
        *nlines = 3;
        *nrows = 3;
        return 0;
    case 3:
        *figure = &oscillator[0][0];
        *nlines = 12;
        *nrows = 11;
        return 0;
    case 4:
        *figure = &pentapole[0][0];
        *nlines = 12;
        *nrows = 12;
        return 0;
    case 5:
        *figure = &tennis[0][0];
        *nlines = 7;
        *nrows = 35;
        return 0;
    case 6:
        *figure = &spaceship[0][0];
        *nlines = 4;
        *nrows = 5;
        return 0;
    case 7:
        *figure = &dragonfly[0][0];
        *nlines = 6;
        *nrows = 7;
        return 0;
    case 8:
        *figure = &gun[0][0];
        *nlines = 9;
        *nrows = 36;
        return 0;
    }

    return 1;
}
