#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;
int dp[MAX + 1];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMinCnt(int n) {
    dp[1] = 0;
    for (int idx = 2; idx <= n; idx++) {
        dp[idx] = dp[idx - 1] + 1;
        if (idx % 2 == 0) dp[idx] = min(dp[idx], dp[idx / 2] + 1);
        if (idx % 3 == 0) dp[idx] = min(dp[idx], dp[idx / 3] + 1);
    }
    return dp[n];
}

int main() {
    init();
    int N;
    cin >> N;
    int ans = findMinCnt(N);
    cout << ans;
    return 0;
}