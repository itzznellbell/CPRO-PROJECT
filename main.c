#include <stdio.h>
#include <stdlib.h>
#include "twixt.h"

int main(){

    for (int i=0; i<24; i++){
        for (int j=0; j<24; j++){
            //board[i][j] = malloc(sizeof(cell));
            board[i][j].player_data = '.';
            for (int k=0; k<8; k++) board[i][j].connections[k] = NULL;
        }
    }

    printf("\n");

    printf(" .----------------.  .----------------.  .----------------.  .----------------.  .----------------. \n"
            "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n"
            "| |  _________   | || | _____  _____ | || |     _____    | || |  ____  ____  | || |  _________   | |\n"
            "| | |  _   _  |  | || ||_   _||_   _|| || |    |_   _|   | || | |_  _||_  _| | || | |  _   _  |  | |\n"
            "| | |_/ | | \\_|  | || |  | | /\\ | |  | || |      | |     | || |   \\ \\  / /   | || | |_/ | | \\_|  | |\n"
            "| |     | |      | || |  | |/  \\| |  | || |      | |     | || |    > `' <    | || |     | |      | |\n"
            "| |    _| |_     | || |  |   /\\   |  | || |     _| |_    | || |  _/ /'`\\ \\_  | || |    _| |_     | |\n"
            "| |   |_____|    | || |  |__/  \\__|  | || |    |_____|   | || | |____||____| | || |   |_____|    | |\n"
            "| |              | || |              | || |              | || |              | || |              | |\n"
            "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n"
            "'----------------'  '----------------'  '----------------'  '----------------'  '----------------'  \n");

    printf("\n\n WELCOME TO TWIXT!\n\n");
    printf(" TWIXT RULES:\n");
    printf(" 1. Place pegs on the terminal in the form of row x col eg:(G15) on your turn.\n");
    printf(" 2. Connect your pegs using knight-move bridges.\n");
    printf(" 3. Bridges cannot cross.\n");
    printf(" 4. Connect your two sides to win.\n\n\n");

    printf("1 -> RED\n");
    printf("2 -> BLUE\n");
    int player1, player2;
    int current_player = 1;

    while(1){
        printf("\nPLAYER 1 CHOOSE YOUR COLOR: ");
        scanf("%d", &player1);
        if(player1 ==1 || player1 == 2)
        {
            player2 = player1*2%3;
            break;
        }
        else printf("INVALID! TRY AGAIN\n");
    }

    printf("\nPlayer 1 is %s\n", player1 == RED ? "RED" : "BLUE");
    printf("Player 2 is %s\n\n", player2 == RED ? "RED" : "BLUE");

    print_board();
    current_player = 1;
    
    int row, col;
    char alpha_row;

    int p1_win = 0, p2_win = 0;
    while(p1_win == 0 && p2_win == 0){
            printf("Player %d Move: ", current_player); 
            clearInputBuffer();
            scanf (" %c %d", &alpha_row, &col);

            if (alpha_row >= 'a' && alpha_row <= 'z') alpha_row = alpha_row - ('a' - 'A');
            row = alpha_row - 'A';
            col--;
            if (row > 23 || col > 23 || row < 0 || col < 0){
                printf("Invalid Move: Out of bounds\n");
                continue;
            }

            else if (board[row][col].player_data != '.') {
                printf("Invalid Move: Spot already taken\n");
                continue;
            }

            char symbol;
            if (current_player == 1)
                symbol = (player1 == RED) ? 'R' : 'B';
            else
                symbol = (player2 == RED) ? 'R' : 'B';

            board[row][col].player_data = symbol; 
            current_player = (current_player*2)%3;
            print_board();
    }
}
