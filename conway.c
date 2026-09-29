#include "conway.h"

int count_alive(char field[HEIGHT][WIDTH], int row, int col)
{
    int count = 0;

    for (int r = row - 1; r <= row + 1; r++) {
        for (int c = col - 1; c <= col + 1; c++) {
            if (r == row && c == col)
                continue;

            if (r >= 0 && r < HEIGHT && c >= 0 && c < WIDTH) {
                if (field[r][c] == ALIVE)
                    count++;
            }
        }
    }

    return count;
}

void evolve(char field[HEIGHT][WIDTH])
{
    char next[HEIGHT][WIDTH];

    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            int neighbours = count_alive(field, r, c);

            if (field[r][c] == ALIVE) {
                if (neighbours == 2 || neighbours == 3)
                    next[r][c] = ALIVE;
                else
                    next[r][c] = ' ';
            } else {
                if (neighbours == 3)
                    next[r][c] = ALIVE;
                else
                    next[r][c] = ' ';
            }
        }
    }

    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            field[r][c] = next[r][c];
        }
    }
}
