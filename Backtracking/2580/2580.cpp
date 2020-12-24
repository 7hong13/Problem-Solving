#include <iostream>
using namespace std;
int board[9][9];
bool colUsed[9][9 + 1];
bool rowUsed[9][9 + 1];
bool square[9][9 + 1];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int changeToSquareId(int row, int col) {
    return 3 * (row / 3) + (col / 3);
}

void dfs(int cnt) {
    if (cnt == 81) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                cout << board[row][col] << ' ';
            }
            cout << "\n";
        }
        exit(0);
    }
    int row = cnt / 9;
    int col = cnt % 9;
    if (board[row][col]) {
        dfs(cnt + 1);
    }
    else {
        for (int num = 1; num <= 9; num++) {
            int squareId = changeToSquareId(row, col);
            if (!colUsed[col][num] && !rowUsed[row][num] && !square[squareId][num]) {
                colUsed[col][num] = rowUsed[row][num] = square[squareId][num] = true;
                board[row][col] = num;
                dfs(cnt + 1);
                colUsed[col][num] = rowUsed[row][num] = square[squareId][num] = false;
                board[row][col] = 0;
            }
        }
    }
}
int main() {
    init();
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cin >> board[row][col]; 
            if (board[row][col]) {
                int num = board[row][col];
                colUsed[col][num] = true;
                rowUsed[row][num] = true;
                square[changeToSquareId(row, col)][num] = true;
            }
        }
    }
    dfs(0);
    return 0;
}