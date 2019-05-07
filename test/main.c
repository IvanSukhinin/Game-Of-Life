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
