#include "figures.h"
#include "life.h"

#include <stdio.h>
#include <unistd.h>

int main()
{
    unsigned char field[FIELD_SIZE][FIELD_SIZE];

    game_of_life(field, &tumbler[0][0], 6, 7);

    return 0;
}
