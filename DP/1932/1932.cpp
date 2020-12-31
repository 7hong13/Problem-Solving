#include <iostream>
#include <algorithm>
using namespace std;
int n, tri[501][501], dp[501][501];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMaxValue() {
    dp[0][0] = tri[0][0];
    for (int row = 1; row < n; row++) {
        dp[row][0] = dp[row - 1][0] + tri[row][0];
        for (int col = 1; col < row; col++) {
            dp[row][col] = max(dp[row - 1][col - 1], dp[row - 1][col])
                + tri[row][col];
        }
        dp[row][row] = dp[row - 1][row - 1] + tri[row][row];
    }
    int mx = -1;
    for (int col = 0; col < n; col++) {
        mx = max(mx, dp[n - 1][col]);
    }
    return mx;
}

int main() {
    init();
    cin >> n;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col <= row; col++) {
            cin >> tri[row][col];
        }
    }
    int ans = findMaxValue();
    cout << ans;
    return 0;
}