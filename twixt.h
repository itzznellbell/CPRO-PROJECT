#ifndef TWIXT_H
#define TWIXT_H

#define NONE 0
#define RED 1
#define BLUE 2

typedef struct cell{
    char player_data;
    //int connections[8]; // 0 to 7 where 0 is 1'o'clock and 7 is 11'o'clock
    struct cell* connections[8];
}cell;

extern cell board[24][24];

void clearInputBuffer();
void print_board();

#endif
