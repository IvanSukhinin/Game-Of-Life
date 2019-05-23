#define CTEST_MAIN
#define CTEST_COLOR_OK

#include <ctest.h>
#include <field.h>
#include <logic.h>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(logic_test, get_count_neighbours_max)
{
    // Given
    const int field_size = 7;
    unsigned char field[7 * 7] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
            1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    int i = 2, j = 2;

    // When
    const int result = get_count_neighbours(field_size, field, i, j);

    // Then
    const int expected = 5;
    ASSERT_EQUAL(expected, result);
}

CTEST(logic_test, get_count_neighbours_empty)
{
    // Given
    const int field_size = 7;
    unsigned char field[7 * 7] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
            1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    int i = 1, j = 5;

    // When
    const int result = get_count_neighbours(field_size, field, i, j);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(logic_test, life)
{
    // Given
    unsigned char cell = 0;
    int neighbour_cell_count = 3;

    // When
    const int result = life_or_death(cell, neighbour_cell_count);

    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(logic_test, death)
{
    // Given
    unsigned char cell = 1;
    int neighbour_cell_count = 5;

    // When
    const int result = life_or_death(cell, neighbour_cell_count);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(logic_test, pass)
{
    // Given
    unsigned char cell = 1;
    int neighbour_cell_count = 2;

    // When
    const int result = life_or_death(cell, neighbour_cell_count);

    // Then
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(logic_test, all_life)
{
    // Given
    const int field_size = 7;
    const int size = field_size - 2;
    unsigned char neighbours[size * size];
    unsigned char field_test[field_size * field_size];
    for (int i = 0; i < field_size; i++) {
        for (int j = 0; j < field_size; j++) {
            field_test[i * field_size + j] = 1;
        }
    }

    // When
    for (int i = 1; i < field_size - 1; i++) {
        for (int j = 1; j < field_size - 1; j++) {
            neighbours[(i - 1) * size + (j - 1)]
                    = get_count_neighbours(field_size, field_test, i, j);
        }
    }

    // Then
    unsigned char expected[size * size];
    for (int i = 1; i < field_size - 1; i++) {
        for (int j = 1; j < field_size - 1; j++) {
            expected[(i - 1) * size + (j - 1)] = 8;
        }
    }

    ASSERT_DATA(expected, size * size, neighbours, size * size);
}

CTEST(logic_test, all_death)
{
    // Given
    const int field_size = 7;
    const int size = field_size - 2;
    unsigned char neighbours[size * size];
    unsigned char field_test[field_size * field_size];
    for (int i = 0; i < field_size; i++) {
        for (int j = 0; j < field_size; j++) {
            field_test[i * field_size + j] = 0;
        }
    }

    // When
    for (int i = 1; i < field_size - 1; i++) {
        for (int j = 1; j < field_size - 1; j++) {
            neighbours[(i - 1) * size + (j - 1)]
                    = get_count_neighbours(field_size, field_test, i, j);
        }
    }

    // Then
    unsigned char expected[size * size];
    for (int i = 1; i < field_size - 1; i++) {
        for (int j = 1; j < field_size - 1; j++) {
            expected[(i - 1) * size + (j - 1)] = 0;
        }
    }

    ASSERT_DATA(expected, size * size, neighbours, size * size);
}

CTEST(move_test, life_imitation)
{
    // Given
    const int field_size = 7;
    unsigned char field[7 * 7] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
            1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    unsigned char temp_field[field_size * field_size];
    int neighbour_cell_count;
    int cell_life;
    // When

    field_copy(field_size, field, temp_field);

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

    // Then
    unsigned char expected[7 * 7] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
            1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    ASSERT_DATA(
            expected, field_size * field_size, field, field_size * field_size);
}