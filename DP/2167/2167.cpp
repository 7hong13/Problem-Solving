#include <iostream>
#include <cstring>
using namespace std;
int N, M, K;
int i, j, x, y;
int arr[301][301], dp[301][301];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void setDpArr() {
    for (int row = 1; row <= N; row++) {
        for (int col = 2; col <= M; col++) {
            dp[row][col] += dp[row][col - 1];
        }
    }
}

int findSumOfArr() { 
    int sum = 0;
    for (int row = i; row <= x; row++) {
        sum += dp[row][y] - dp[row][j - 1];
    }
    return sum;
}

int main() {
    init();
    cin >> N >> M;
    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= M; col++) {
            cin >> arr[row][col];
            dp[row][col] = arr[row][col];
        }
    }
    setDpArr();
    cin >> K;
    while (K--) {
        cin >> i >> j >> x >> y;
        int sum = findSumOfArr();
        cout << sum << "\n";
    }
    return 0;
}