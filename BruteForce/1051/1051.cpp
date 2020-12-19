#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int N, M;
int square[51][51];
void init() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMaxSquare() {
    int max = 1;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            int val = square[row][col];
            for (int d = 1; row + d < N && col + d < M; d++) {
                if (square[row][col + d] != val) continue;
                if (square[row + d][col] != val) continue;
                if (square[row + d][col + d] != val) continue;
                if (max < pow(d + 1, 2)) {
                    max = pow(d + 1, 2);
                }
            }
        }
    }
    return max;
}

int main() {
    init();
    cin >> N >> M;
    for (int row = 0; row < N; row++) {
            string rowNum;
            cin >> rowNum;
        for (int col = 0; col < M; col++) {
            square[row][col] = rowNum[col] - 48;
        }
    }
    int maxVal = findMaxSquare();
    cout << maxVal << "\n";
    return 0;
}