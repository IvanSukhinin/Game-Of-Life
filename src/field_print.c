#include "field_print.h"

void print_field(
        unsigned char field[FIELD_SIZE][FIELD_SIZE],
        GtkWidget* buttons[FIELD_SIZE][FIELD_SIZE])
{
    /*Вывод поля*/
    for (int i = 1; i < FIELD_SIZE - 1; i++) {
        for (int j = 1; j < FIELD_SIZE - 1; j++) {
            if (field[i][j] == 0) {
                gtk_widget_set_name(buttons[i][j], "cell");
            } else if (field[i][j] == 1) {
                gtk_widget_set_name(buttons[i][j], "cell_green");
            }
        }
    }
}
