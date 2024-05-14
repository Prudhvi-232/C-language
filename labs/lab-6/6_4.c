#include <stdio.h>
char board[3][3];

void initializeBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("  0 1 2\n");
    for (int i = 0; i < 3; ++i) {
        printf("%d ", i);
        for (int j = 0; j < 3; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }
    return 0;
}

int main() {
    int row, col, currentPlayer = 1;
    char symbol;

    initializeBoard();

    while (1) {
        printf("Player %d, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            symbol = (currentPlayer == 1) ? 'X' : 'O';
            board[row][col] = symbol;
            printBoard();

            if (checkWin()) {
                printf("Player %d wins! Congratulations!\n", currentPlayer);
                break;
            }

            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    return 0;
}