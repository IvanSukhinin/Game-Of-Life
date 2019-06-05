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

    while (quit_flag) {
        print_field(field_size, field, buttons);
        main_logic(field_size, field);
        gtk_main_iteration();
    }
}
