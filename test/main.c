#define CTEST_MAIN
#define CTEST_COLOR_OK

#include <const.h>
#include <ctest.h>
#include <logic.h>

unsigned char field[FIELD_SIZE][FIELD_SIZE] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
};

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(logic_test, get_count_neighbours_max)
{
    // Given
    int i = 2, j = 2;

    // When
    const int result = get_count_neighbours(field, i, j);

    // Then
    const int expected = 5;
    ASSERT_EQUAL(expected, result);
}

CTEST(logic_test, get_count_neighbours_empty)
{
    // Given
    int i = 1, j = 5;

    // When
    const int result = get_count_neighbours(field, i, j);

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
    unsigned char neighbours[FIELD_SIZE];
    unsigned char field_test[FIELD_SIZE][FIELD_SIZE];
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            field_test[i][j] = 1;
        }
    }

    // When
    int j = 1;
    for (int i = 0; i < FIELD_SIZE - 2; i++) {
        neighbours[i] = get_count_neighbours(field_test, i + 1, j);
    }

    // Then
    unsigned char expected[FIELD_SIZE];
    for (int i = 0; i < FIELD_SIZE - 2; i++) {
        expected[i] = 8;
    }

    ASSERT_DATA(expected, FIELD_SIZE - 2, neighbours, FIELD_SIZE - 2);
}

CTEST(logic_test, all_death)
{
    // Given
    unsigned char neighbours[FIELD_SIZE];
    unsigned char field_test[FIELD_SIZE][FIELD_SIZE];
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            field_test[i][j] = 0;
        }
    }

    // When
    int j = 1;
    for (int i = 0; i < FIELD_SIZE - 2; i++) {
        neighbours[i] = get_count_neighbours(field_test, i + 1, j);
    }

    // Then
    unsigned char expected[FIELD_SIZE];
    for (int i = 0; i < FIELD_SIZE - 2; i++) {
        expected[i] = 0;
    }

    ASSERT_DATA(expected, FIELD_SIZE - 2, neighbours, FIELD_SIZE - 2);
}
