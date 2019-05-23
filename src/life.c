#include "life.h"
#include "field.h"
#include "field_print.h"
#include "gui.h"
#include "logic.h"

#include <unistd.h>

void game_of_life(int argc, char* argv[], const int field_size)
{
    /*Game of Life*/
    unsigned char field[field_size * field_size];
    init_field(field_size, field);

    GtkWidget* buttons[field_size][field_size];
    int quit_flag = 1;
    gui(argc, argv, field_size, buttons, &quit_flag, field);

    unsigned char temp_field[field_size * field_size];

    while (quit_flag) {
        print_field(field_size, field, buttons);
        usleep(15000);

        field_copy(field_size, field, temp_field);

        int neighbour_cell_count;
        int cell_life;
        for (int i = 1; i < field_size - 1; i++) {
            for (int j = 1; j < field_size - 1; j++) {
                neighbour_cell_count
                        = get_count_neighbours(field_size, temp_field, i, j);
                cell_life = life_or_death(
                        temp_field[i * field_size + j], neighbour_cell_count);
                if (cell_life == 1) {
                    field[i * field_size + j] = 1;
                } else if (cell_life == 0) {
                    field[i * field_size + j] = 0;
                }
            }
        }
        gtk_main_iteration();
    }
}
