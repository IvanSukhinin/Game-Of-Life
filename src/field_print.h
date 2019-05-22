#pragma once

#include "const.h"

#include <gtk/gtk.h>

void print_field(
        unsigned char field[FIELD_SIZE][FIELD_SIZE],
        GtkWidget* buttons[FIELD_SIZE][FIELD_SIZE]);
