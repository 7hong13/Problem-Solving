#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int dp[100001];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMinCnt(int n) {
    for (int num = 1; pow(num, 2) <= n; num++) {
        int idx = pow(num, 2);
        dp[idx] = 1;
    }
    for (int idx = 2; idx <= n; idx++) {
        if (dp[idx] == 1) continue;
        dp[idx] = idx;
        for (int prevIdx = 1; pow(prevIdx, 2) < idx; prevIdx++) {
            dp[idx] = min(dp[idx], dp[idx - prevIdx * prevIdx] + 1);
        }
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