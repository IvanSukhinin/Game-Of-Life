#include "life.h"
#include "field.h"
#include "field_print.h"
#include "figures.h"
#include "logic.h"
#include "gui.h"

#include <unistd.h>

void game_of_life(int argc, char* argv[])
{
    /*Game of Life*/
    unsigned char field[FIELD_SIZE][FIELD_SIZE];
    init_field(field);


    GtkWidget* buttons[FIELD_SIZE][FIELD_SIZE];
    int quit_flag = 1;
    gui(argc, argv, buttons, &quit_flag);

    unsigned char temp_field[FIELD_SIZE][FIELD_SIZE];

    while (quit_flag) {
        print_field(field, buttons);
        usleep(20000);

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
        }
        gtk_main_iteration();
    }
}

