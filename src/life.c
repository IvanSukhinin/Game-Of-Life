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
    /*Game of Life*/
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
