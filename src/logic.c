#include "logic.h"

int get_count_neighbours(
        unsigned char field[FIELD_SIZE][FIELD_SIZE], int i, int j)
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

int life_or_death(unsigned char cell, int neighbour_cell_count)
{
    /*В зависимости от кол-ва соседей клетка либо умирает (0), либо рождается
     * (1), либо с ней ничего не происходит (2)*/
    if (neighbour_cell_count == 3 && cell == 0) {
        return 1;
    }
    if ((neighbour_cell_count > 3 || neighbour_cell_count < 2) && cell == 1) {
        return 0;
    }

    return 2;
}
