#include <stdio.h>
#include <unistd.h>
#include "conway.h"

void dump_field(char field[HEIGHT][WIDTH])
{
    printf("\033[H\033[J");

    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            putchar(field[r][c]);
        }
        putchar('\n');
    }
}

int main(void)
{
    char field[HEIGHT][WIDTH] = {0};

    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            field[r][c] = ' ';
        }
    }

    /* Starting glider pattern */
    field[1][2] = ALIVE;
    field[2][3] = ALIVE;
    field[3][1] = ALIVE;
    field[3][2] = ALIVE;
    field[3][3] = ALIVE;

    for (int generation = 0; generation < 50; generation++) {
        printf("Generation %d\n", generation);
        dump_field(field);
        evolve(field);
        sleep(1);
    }

    return 0;
}
