#include "logic.h"

int get_count_neighbours(unsigned char field[FIELD_SIZE][FIELD_SIZE], int i, int j)
{
    /*Количество соседних живых клеток*/
    int neighbour_cell_count = 0;

    if (field[i][j + 1] == 1) {
        neighbour_cell_count++;
    }
    if (field[i + 1][j + 1]) {
        neighbour_cell_count++;
    }
    if (field[i + 1][j] == 1) {
        neighbour_cell_count++;
    }
    if (field[i + 1][j - 1] == 1) {
        neighbour_cell_count++;
    }
    if (field[i][j - 1] == 1) {
        neighbour_cell_count++;
    }
    if (field[i - 1][j - 1] == 1) {
        neighbour_cell_count++;
    }
    if (field[i - 1][j] == 1) {
        neighbour_cell_count++;
    }
    if (field[i - 1][j + 1] == 1) {
        neighbour_cell_count++;
    }

    return neighbour_cell_count;
}