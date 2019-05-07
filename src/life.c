#include "life.h"
#include "field.h"
#include "field_print.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void game_of_life(
	    unsigned char field[FIELD_SIZE][FIELD_SIZE],
        unsigned char figure[],
        int nlines,
        int ncols)
{
	make_field(field, figure, nlines, ncols);
	while (1) {
        clear_screen();
        printf("Press ctrl + c to exit\n");
        print_field(field);
        usleep(200000);
	}
}
