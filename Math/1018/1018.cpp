#include <iostream>
using namespace std;
char chessBoard[51][51];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int m, n;
    cin >> n >> m;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> chessBoard[row][col];
        }
    }
    int min = 10000;
    //맨위 맨왼쪽 흰색
    for (int row = 0; row <= n - 8; row++) {
        for (int col = 0; col <= m - 8; col++) {
            int cnt = 0;
            for (int subRow = row; subRow < row + 8; subRow++)  {
                for (int subCol = col; subCol < col + 8; subCol++) {
                    if (subRow % 2 == 0 && subCol % 2 == 0) {
                        cnt = chessBoard[subRow][subCol] == 'W' ? cnt : cnt + 1;
                    }
                    else if (subRow % 2 == 0 && subCol % 2 != 0) {
                        cnt = chessBoard[subRow][subCol] == 'B' ? cnt : cnt + 1;
                    }
                    else if (subRow % 2 != 0 && subCol % 2 == 0) {
                        cnt = chessBoard[subRow][subCol] == 'B' ? cnt : cnt + 1;
                    }
                    else if (subRow % 2 != 0 && subCol % 2 != 0) {
                        cnt = chessBoard[subRow][subCol] == 'W' ? cnt : cnt + 1;
                    }
                }
            }
            //맨위 맨왼쪽 검은색
            cnt = 64 - cnt < cnt ? 64 - cnt : cnt;
            min = min < cnt ? min : cnt;
        }
    }
    cout << min << "\n";
    return 0;
}