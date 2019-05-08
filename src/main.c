#include "life.h"

#include <stdio.h>
#include <unistd.h>

int main()
{
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

    return 0;
}
