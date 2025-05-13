#include <stdio.h>
#include <stdbool.h>

#define N 5 


void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '-');
        }
        printf("\n");
    }
}


bool isSafe(int board[N][N], int row, int col) {
    int i, j;

   
    for (i = 0; i < row; i++) {
        if (board[i][col]) return false;
    }

   
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }

    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) return false;
    }

    return true;
}


bool solveNQueensUtil(int board[N][N], int row) {
    if (row == N) {
        return true; 
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            if (solveNQueensUtil(board, row + 1)) {
                return true;
            }

            board[row][col] = 0; 
        }
    }

    return false;
}

bool solveNQueens() {
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0)) {
        printf("No solution exists for N = %d\n", N);
        return false;
    }

    printSolution(board);
    return true;
}

// Driver code
int main() {
    solveNQueens();
    return 0;
}

/*
output:
Q - - - - 
- - Q - -
- - - - Q
- Q - - -
- - - Q -
*/
