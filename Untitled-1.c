#include <stdio.h>
#include<conio.h>

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) // Rows
            return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) // Columns
            return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) // Diagonal
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) // Diagonal
        return 1;
    return 0;
}

// Function to check if the board is full (draw)
int isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0; // Empty cell found, board is not full
    return 1; // No empty cells found, board is full
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col;
    char currentPlayer = 'X';



    while (1) {
        // Display the board
        displayBoard(board);

        // Take input for row and column
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check if the cell is empty and within bounds
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                printf("Player %c wins!\n", currentPlayer);
                break;
            }

            // Check for draw
            if (isBoardFull(board)) {
                displayBoard(board);
                printf("It's a draw!\n");
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move! Please try again.");
        }
    }

    getch();
}
