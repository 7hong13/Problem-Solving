#include <iostream>
using namespace std;
int M, N;
char chessBoard[50][50];
void init() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int countMinimumColoring() {
    int minCnt = 99999999;
    for (int row = 0; row <= N - 8; row++) {
        for (int col = 0; col <= M - 8; col++) {
            int cnt = 0;
            for (int subRow = row; subRow < row + 8; subRow++) {
                for (int subCol = col; subCol < col + 8; subCol++) {
                    if (subRow % 2 == 0 && subCol % 2 == 0 
                        && chessBoard[subRow][subCol] == 'B') cnt++;
                    else if (subRow % 2 != 0 && subCol % 2 == 0 
                        && chessBoard[subRow][subCol] == 'W') cnt++;
                    else if (subRow % 2 == 0 && subCol % 2 != 0 
                        && chessBoard[subRow][subCol] == 'W') cnt++;
                    else if (subRow % 2 != 0 && subCol % 2 != 0 
                        && chessBoard[subRow][subCol] == 'B') cnt++;
                }
            }
            cnt = 64 - cnt < cnt ? 64 - cnt : cnt;
            minCnt = cnt < minCnt ? cnt : minCnt;
        }
    }
    return minCnt;
}

int main() {
    init();
    cin >> N >> M;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> chessBoard[row][col];
        }
    }
    int cnt = countMinimumColoring();
    cout << cnt << "\n";
    return 0;
}