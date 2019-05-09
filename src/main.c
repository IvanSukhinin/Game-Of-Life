//#include "life.h"

#include <gtk/gtk.h>
//#include <stdio.h>
//#include <unistd.h>

int main(int argc, char* argv[])
{
    /*
    unsigned char field[FIELD_SIZE][FIELD_SIZE];

    unsigned char* figure;
    int nlines, nrows;
    int check_input;
    check_input = input(&figure, &nlines, &nrows);
    if (check_input == 1) {
        printf("Err input\n");
        return -1;
    }

    game_of_life(field, figure, nlines, nrows);
    */
    GtkWidget* window;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_title(GTK_WINDOW(window), "Game of Life");

    g_signal_connect(
            G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
