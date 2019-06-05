#include "field_print.h"

void print_field(
        const int field_size,
        unsigned char field[],
        GtkWidget* buttons[field_size][field_size])
{
    /*Вывод поля*/
    usleep(15000);
    for (int i = 1; i < field_size - 1; i++) {
        for (int j = 1; j < field_size - 1; j++) {
            if (field[i * field_size + j] == 0) {
                gtk_widget_set_name(buttons[i][j], "cell");
            } else if (field[i * field_size + j] == 1) {
                gtk_widget_set_name(buttons[i][j], "cell_green");
            }
        }
    }
}
