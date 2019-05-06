#include <stdio.h>

#define FIELD_SIZE 20

void print_field(unsigned char field[FIELD_SIZE][FIELD_SIZE]);
void init_field(unsigned char field[FIELD_SIZE][FIELD_SIZE]);

int main()
{
    unsigned char field[FIELD_SIZE][FIELD_SIZE];

    init_field(field);

    print_field(field);

    return 0;
}

void print_field(unsigned char field[FIELD_SIZE][FIELD_SIZE])
{
    /*Вывод поля*/
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            if (field[i][j] == 0) {
                printf("# ");
            }
        }
        printf("\n");
    }
}

void init_field(unsigned char field[FIELD_SIZE][FIELD_SIZE])
{
    /*Инициализация поля*/
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            field[i][j] = 0;
        }
    }
}
