#ifndef CONWAY_H
#define CONWAY_H

#define WIDTH 20
#define HEIGHT 10
#define ALIVE 'X'

int count_alive(char field[HEIGHT][WIDTH], int row, int col);
void evolve(char field[HEIGHT][WIDTH]);

#endif
