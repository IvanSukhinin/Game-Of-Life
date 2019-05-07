#include "life.h"
#include "field.h"
#include "logic.h"
#include "field_print.h"

#include <stdio.h>
#include <unistd.h>

void game_of_life(
        unsigned char field[FIELD_SIZE][FIELD_SIZE],
        unsigned char figure[],
        int nlines,
        int ncols)
{
    make_field(field, figure, nlines, ncols);
    while (1) {
        clear_screen();
        printf("Press ctrl + c to exit\n");
        print_field(field);
        usleep(200000);

        int neighbour_cell_count;

        for (int i = 1; i < FIELD_SIZE - 1; i++) {
            for (int j = 1; j < FIELD_SIZE - 1; j++) {
                neighbour_cell_count = get_count_neighbours(field, i, j);
                printf("%d ", neighbour_cell_count);
            }
            printf("\n");
        }

    }
}
