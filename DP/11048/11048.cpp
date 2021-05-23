#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;
int dp[MAX][MAX];
int N, M;
int dx[3] = {0, -1, -1}; //col
int dy[3] = {-1, 0, -1}; //row
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMaxSum() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            int mx = 0;
            for (int idx = 0; idx < 3; idx++) {
                int x = col + dx[idx];
                int y = row + dy[idx];
                if (x < 0 || y < 0) continue;
                mx = max(mx, dp[y][x]);
            }
            dp[row][col] += mx;
        }
    }
    return dp[N - 1][M - 1];
}

int main() {
    init();
    cin >> N >> M;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> dp[row][col];
        }
    }
    int ans = findMaxSum();
    cout << ans;
    return 0;
}