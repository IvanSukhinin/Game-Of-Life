#pragma once

#include <gtk/gtk.h>

#include "const.h"

void gui(
        int argc,
        char* argv[],
        GtkWidget* buttons[FIELD_SIZE][FIELD_SIZE],
        int* quit_flag);
void create_menu(
        GtkWidget** vbox, GtkWidget** menu_grid, GtkWidget* menu_button[8]);
void create_buttons_grid(
        GtkWidget* buttons[FIELD_SIZE][FIELD_SIZE], GtkWidget** grid);
void include_css();
void create_window(GtkWidget** window, gint width, gint height);
void create_grid(GtkWidget** grid, GtkWidget** window, const gchar* name);
void quit(GtkWidget* window, gpointer user_data);
