#pragma once

#include <gtk/gtk.h>

#include "const.h"

void gui(int argc, char* argv[]);
void include_css();
void create_window(GtkWidget** window, gint width, gint height);
void create_grid(GtkWidget** grid, GtkWidget** window, const gchar* name);
