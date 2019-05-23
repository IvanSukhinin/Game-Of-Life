#pragma once

#include <gtk/gtk.h>

void gui(
        int argc,
        char* argv[],
        const int field_size,
        GtkWidget* buttons[field_size][field_size],
        int* quit_flag,
        unsigned char field[]);
void create_buttons_grid(
        const int field_size,
        GtkWidget* buttons[field_size][field_size],
        GtkWidget** grid);
void create_menu(
        GtkWidget** vbox, GtkWidget** menu_grid, GtkWidget* menu_button[8]);
void signal_events(
        GtkWidget* menu_button[8], const int field_size, unsigned char field[]);
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
