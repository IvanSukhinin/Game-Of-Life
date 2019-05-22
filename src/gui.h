#pragma once

#include <gtk/gtk.h>

#include "const.h"

void gui(
        int argc,
        char* argv[],
        GtkWidget* buttons[FIELD_SIZE][FIELD_SIZE],
        int* quit_flag,
        unsigned char field[FIELD_SIZE][FIELD_SIZE]);
void create_buttons_grid(
        GtkWidget* buttons[FIELD_SIZE][FIELD_SIZE], GtkWidget** grid);
void create_menu(
        GtkWidget** vbox, GtkWidget** menu_grid, GtkWidget* menu_button[8]);
void signal_events(
        GtkWidget* menu_button[8], unsigned char field[FIELD_SIZE][FIELD_SIZE]);
void include_css();
void create_window(GtkWidget** window, gint width, gint height);
void create_grid(GtkWidget** grid, GtkWidget** window, const gchar* name);
void quit(GtkWidget* window, gpointer user_data);
void tumbler_click(GtkButton* button, gpointer user_data);
void glider_click(GtkButton* button, gpointer user_data);
void oscillator_click(GtkButton* button, gpointer user_data);
void pentapole_click(GtkButton* button, gpointer user_data);
void tennis_click(GtkButton* button, gpointer user_data);
void spaceship_click(GtkButton* button, gpointer user_data);
void dragonfly_click(GtkButton* button, gpointer user_data);
void gun_click(GtkButton* button, gpointer user_data);
