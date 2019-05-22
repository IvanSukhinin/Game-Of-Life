#include "gui.h"

void gui(
        int argc,
        char* argv[],
        GtkWidget* buttons[FIELD_SIZE][FIELD_SIZE],
        int* quit_flag)
{
    /*Отображение окна*/
    GtkWidget *window, *vbox, *grid, *menu_grid, *menu_button[8];

    gtk_init(&argc, &argv);

    include_css();

    create_window(&window, 600, 800);
    g_signal_connect(window, "destroy", G_CALLBACK(quit), quit_flag);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    create_grid(&grid, &window, "grid");
    gtk_box_pack_start(GTK_BOX(vbox), grid, TRUE, TRUE, 0);

    create_buttons_grid(buttons, &grid);

    create_grid(&menu_grid, &window, "menu");
    create_menu(&vbox, &menu_grid, menu_button);

    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_show_all(window);
}

void create_menu(
        GtkWidget** vbox, GtkWidget** menu_grid, GtkWidget* menu_button[8])
{
    /*Создание меню*/
    menu_button[0] = gtk_button_new_with_label("Tumbler");
    menu_button[1] = gtk_button_new_with_label("Glider");
    menu_button[2] = gtk_button_new_with_label("Oscillator");
    menu_button[3] = gtk_button_new_with_label("Pentapole");
    menu_button[4] = gtk_button_new_with_label("Tennis");
    menu_button[5] = gtk_button_new_with_label("Spaceship");
    menu_button[6] = gtk_button_new_with_label("Dragonfly");
    menu_button[7] = gtk_button_new_with_label("Gun");

    for (int i = 0; i < 8; i++) {
        gtk_widget_set_name(menu_button[i], "menu_buttons");
        gtk_grid_attach(GTK_GRID(*menu_grid), menu_button[i], i, 0, 1, 1);
    }

    gtk_box_pack_start(GTK_BOX(*vbox), *menu_grid, TRUE, TRUE, 0);
}

void create_buttons_grid(
        GtkWidget* buttons[FIELD_SIZE][FIELD_SIZE], GtkWidget** grid)
{
    /*Создание клеток*/
    for (int i = 1; i < FIELD_SIZE - 1; i++) {
        for (int j = 1; j < FIELD_SIZE - 1; j++) {
            buttons[i][j] = gtk_button_new();
            gtk_widget_set_name(buttons[i][j], "cell");
            gtk_grid_attach(GTK_GRID(*grid), buttons[i][j], j, i, 1, 1);
        }
    }
}

void create_window(GtkWidget** window, gint width, gint height)
{
    /*Создание окна*/
    *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(*window), "Game of Life");
    gtk_window_set_default_size(GTK_WINDOW(*window), width, height);
    gtk_window_set_resizable(GTK_WINDOW(*window), TRUE);
}

void quit(GtkWidget* window, gpointer user_data)
{
    int* quit_flag = user_data;
    *quit_flag = 0;
    gtk_main_quit();
}

void create_grid(GtkWidget** grid, GtkWidget** window, const gchar* name)
{
    /*Создание сетки*/
    *grid = gtk_grid_new();
    gtk_grid_set_row_homogeneous(GTK_GRID(*grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(*grid), TRUE);
    gtk_widget_set_name(*grid, name);
}

void include_css()
{
    /*Подключение стилей*/
    GtkCssProvider* provider;
    GdkDisplay* display;
    GdkScreen* screen;

    provider = gtk_css_provider_new();
    display = gdk_display_get_default();
    screen = gdk_display_get_default_screen(display);
    gtk_style_context_add_provider_for_screen(
            screen,
            GTK_STYLE_PROVIDER(provider),
            GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    const gchar* myCssFile = "./src/grid.css";
    GError* error = 0;

    gtk_css_provider_load_from_file(
            provider, g_file_new_for_path(myCssFile), &error);
    g_object_unref(provider);
}
