#include "logic.h"
#include "field.h"

void main_logic(const int field_size, unsigned char field[])
{
    unsigned char temp_field[field_size * field_size];

    field_copy(field_size, field, temp_field);

    int neighbour_cell_count;
    int cell_life;
    for (int i = 1; i < field_size - 1; i++) {
        for (int j = 1; j < field_size - 1; j++) {
            neighbour_cell_count
                    = get_count_neighbours(field_size, temp_field, i, j);
            cell_life = life_or_death(
                    temp_field[i * field_size + j], neighbour_cell_count);
            if (cell_life == 1) {
                field[i * field_size + j] = 1;
            } else if (cell_life == 0) {
                field[i * field_size + j] = 0;
            }
        }
    }
}

int get_count_neighbours(
        const int field_size, unsigned char field[], int i, int j)
{
    /*Количество соседних живых клеток*/
    int neighbour_cell_count = 0;

    if (field[i * field_size + j + 1] == 1) {
        neighbour_cell_count++;
    }
    if (field[(i + 1) * field_size + j + 1] == 1) {
        neighbour_cell_count++;
    }
    if (field[(i + 1) * field_size + j] == 1) {
        neighbour_cell_count++;
    }
    if (field[(i + 1) * field_size + j - 1] == 1) {
        neighbour_cell_count++;
    }
    if (field[i * field_size + j - 1] == 1) {
        neighbour_cell_count++;
    }
    if (field[(i - 1) * field_size + j - 1] == 1) {
        neighbour_cell_count++;
    }
    if (field[(i - 1) * field_size + j] == 1) {
        neighbour_cell_count++;
    }
    if (field[(i - 1) * field_size + j + 1] == 1) {
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
