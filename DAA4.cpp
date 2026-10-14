#include <bits/stdc++.h>
using namespace std;

int fixedRow;   // 0-based row of the pre-placed queen

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Column (whole board)
    for (int i = 0; i < n; i++)
        if (board[i][col] == 1) return false;

    // Upper-left
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) return false;

    // Upper-right
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1) return false;

    // Lower-left
    for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
        if (board[i][j] == 1) return false;

    // Lower-right
    for (int i = row + 1, j = col + 1; i < n && j < n; i++, j++)
        if (board[i][j] == 1) return false;

    return true;
}

bool solve(vector<vector<int>>& board, int row, int n) {
    if (row == n) return true;
    if (row == fixedRow) return solve(board, row + 1, n);  // skip fixed row

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if (solve(board, row+1, n)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

void printBoard(vector<vector<int>>& board, int n) {
    cout << "\nFinal N-Queens Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << board[i][j] << " ";
        cout << endl;
    }
}

int main() {
    string choice;

    while (true) {
        cout << "\n--- N-Queens Menu ---\n";
        cout << "1. Solve N-Queens\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == "1") {
            int n, row, col;

            cout << "Enter N: ";
            cin >> n;
            if (n <= 0) { cout << "Invalid N\n"; continue; }

            cout << "Enter first Queen position (row and column, 1-based): ";
            cin >> row >> col;
            if (row < 1 || row > n || col < 1 || col > n) {
                cout << "Invalid position\n";
                continue;
            }

            vector<vector<int>> board(n, vector<int>(n, 0));
            fixedRow = row - 1;
            board[fixedRow][col - 1] = 1;

            if (solve(board, 0, n)) printBoard(board, n);
            else cout << "No solution found for this initial position.\n";
        }
        else if (choice == "2") break;
        else cout << "Invalid choice\n";
    }
    return 0;
}