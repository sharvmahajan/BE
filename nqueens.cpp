#include<bits/stdc++.h>
using namespace std;
#define ll long long

void printBoard(vector<vector<char>>& board){
    for (auto it : board){
        for (auto ele : it) cout << ele << " ";
        cout << endl;
    }
}

bool isSafe(ll i, ll j, vector<vector<char>>& board){
    for (ll x = 0; x < board.size(); x++){
        if (board[x][j] == 'Q') return false;
    }
    for (ll x = 0; x < board.size(); x++){
        if (board[i][x] == 'Q') return false;
    }
    for (ll x = i, y = j; x >= 0 && y >= 0; x--, y--){
        if (board[x][y] == 'Q') return false;
    }
    for (ll x = i, y = j; x < board.size() && y < board.size(); x++, y++){
        if (board[x][y] == 'Q') return false;
    }
    for (ll x = i, y = j; x >= 0 && y < board.size(); x--, y++){
        if (board[x][y] == 'Q') return false;
    }
    for (ll x = i, y = j; x < board.size() && y >= 0; x++, y--){
        if (board[x][y] == 'Q') return false;
    }
    return true;
}

bool solve(ll i, vector<vector<char>>& board){
    if (i >= board.size()) return true;
    for (ll j = 0; j < board.size(); j++){
        if (isSafe(i, j, board)){
            board[i][j] = 'Q';
            if (solve(i+1, board)) return true;
            board[i][j] = '.';
        }
    }
    return false;
}

void nQueens(ll n, ll col){
    vector<vector<char>> board(n, vector<char>(n, '.'));
    board[0][col] = 'Q';
    if (solve(1, board)){
        printBoard(board);
        return;
    }
    cout << "No solution!" << endl;
}

int main(){
    ll n;
    cin >> n;
    ll col;
    cin >> col;
    nQueens(n, col);
}
