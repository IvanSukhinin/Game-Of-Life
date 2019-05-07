#include "field_print.h"

#include <stdio.h>

void print_field(unsigned char field[FIELD_SIZE][FIELD_SIZE])
{
    /*Вывод поля*/
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            if (field[i][j] == 0) {
                printf("# ");
            } else if (field[i][j] == 1) {
                printf("! ");
            }
        }
        printf("\n");
    }
}
