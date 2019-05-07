#include "field.h"
#include "field_print.h"
#include "figures.h"

#include <stdio.h>

int main()
{
    unsigned char field[FIELD_SIZE][FIELD_SIZE];

    make_field(field, &tumbler[0][0], 6, 7);
    print_field(field);

    return 0;
}
