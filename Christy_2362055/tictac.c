#include <stdio.h>
#define size 3 
void Board(char board[size][size]);
void printboard(char board[size][size]);
int check(char board[size][size]);
int isempty(char board[size][size]);

int main() {
    char board[size][size];
    int row, col;
    char currentPlayer = 'X';
    int gameover = 0;

    Board(board);

    printf("Tic Tac Toe Game\n");

    while (gameover== 0) {
        
        printboard(board);

        
        printf("Player %c, enter your move (row : column): ", currentPlayer);
        scanf("%d %d", &row, &col);

       
        if (row > 0 && row <=size && col >0 && col <=size && board[row-1][col-1] == ' ') {
          
            board[row-1][col-1] = currentPlayer;

            
            if (check(board)) {
                gameover = 1; 
            } else if (isempty(board)) {
                gameover = -1; 
            } else {
               
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    
    printboard(board);

    if (gameover == 1) {
        printf("Player %c wins!\n", currentPlayer);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}

void Board(char board[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = ' ';
        }
    }
}


void printboard(char board[size][size]) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %c ", board[i][j]);
            if (j < size - 1) printf("|");
        }
        printf("\n");
        if (i < size - 1) printf("---+---+---\n");
    }
    printf("\n");
}


int check(char board[size][size]) {
    //checking vertical and horizontal rows and columns
    for (int i = 0; i < size; i++) {
    if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return 1;
        }
    }

    // Check diagonal elemnts
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') || 
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }

    return 0;
}


int isempty(char board[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == ' ') {
                return 0; //board is not full (atleat one positionn is free)
            }
        }
    }
    return 1; 
}
