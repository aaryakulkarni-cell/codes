#include <bits/stdc++.h>
using namespace std;

#define N 4   // change N for different sizes

int board[N][N];

// Function to print solution
void printBoard() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

// Check if safe to place queen
bool isSafe(int row, int col) {

    // Check same column
    for(int i = 0; i < row; i++) {
        if(board[i][col])
            return false;
    }

    // Check left diagonal
    for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
        if(board[i][j])
            return false;
    }

    // Check right diagonal
    for(int i=row, j=col; i>=0 && j<N; i--, j++) {
        if(board[i][j])
            return false;
    }

    return true;
}

// Backtracking function
bool solve(int row) {

    // If all queens placed
    if(row == N) {
        printBoard();
        return true;
    }

    // Try all columns
    for(int col = 0; col < N; col++) {

        if(isSafe(row, col)) {

            // Place queen
            board[row][col] = 1;

            // Recur for next row
            if(solve(row + 1))
                return true;

            // Backtrack (remove queen)
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {

    // Initialize board with 0
    memset(board, 0, sizeof(board));

    if(!solve(0)) {
        cout << "No solution exists";
    }

    return 0;
}