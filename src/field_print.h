#pragma once

#include <gtk/gtk.h>

void print_field(
        const int field_size,
        unsigned char field[],
        GtkWidget* buttons[field_size][field_size]);
