#include <stdio.h>
#include <stdlib.h>
#include "twixt.h"


cell board[24][24];

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void print_board(){
    printf("\n");

    printf("    ");
    
    int j;

    for(j=0; j<9; j++){
            printf(" %d  ",j+1);
        }

        for (j=9; j<24; j++){
            printf("%d  ",j+1);
        }

    printf("\n");

    printf("    ");

    for (j=0; j<24; j++) printf("__  ");

    printf("\n");

    char row[25]="ABCDEFGHIJKLMNOPQRSTUVWX";

    for (int i=0; i<24; i++){
        printf("%c|  ", row[i]);
        // for(j=0; j<9; j++){
        //     printf("%c  ", board[i][j].player_data);
        // }

        // for (j=9; j<24; j++){
        //     printf(" %c  ", board[i][j].player_data);
        // }
        for (j=0; j<24; j++) printf(" %c  ", board[i][j].player_data);
        printf(" |\n");
    }

    printf("    ");

    for (j=0; j<24; j++) printf("__  ");

    printf("\n\n");
}
