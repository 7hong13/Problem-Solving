#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 10000
using namespace std;
int n, mx = -1;
int dp[MAX][2]; //0: 연속합, 1: 비연속합
int wine[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    memset(dp, 0, sizeof(dp));
}

int findMaxWineSum() {
    dp[0][0] = dp[0][1] = wine[0];
    dp[1][0] = wine[0] + wine[1];
    dp[1][1] = max(wine[0], wine[1]);
    mx = dp[1][0];
    for (int idx = 2; idx < n; idx++) {
        for (int subIdx = 1; subIdx < idx - 1; subIdx++) {
            dp[idx][0] = max({dp[idx][0], dp[subIdx][0] + wine[idx], dp[subIdx][1] + wine[idx]});
            dp[idx][1] = max({dp[idx][1], dp[subIdx][0] + wine[idx], dp[subIdx][1] + wine[idx]});
            mx = max({mx, dp[idx][0], dp[idx][1]});
        }
        dp[idx][0] = max(dp[idx][0], dp[idx - 1][1] + wine[idx]);
        dp[idx][1] = max(dp[idx][1], dp[idx - 2][0] + wine[idx]);
        mx = max({mx, dp[idx][0], dp[idx][1]});
    }
    return mx;
}

int main() {
    init();
    cin >> n;
    for (int idx = 0; idx < n; idx++) {
        cin >> wine[idx];
    }
    int ans = findMaxWineSum();
    cout << ans;
    return 0;   
}