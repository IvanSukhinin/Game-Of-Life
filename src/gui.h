#pragma once

#include <gtk/gtk.h>

void gui(int argc, char* argv[]);
void create_window(GtkWidget** window, gint width, gint height);
void create_grid(GtkWidget** grid, GtkWidget** window, const gchar* name);
void include_css();
