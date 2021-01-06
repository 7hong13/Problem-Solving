#include <iostream>
#include <algorithm>
using namespace std;
int N, seq[1001], dp[1001];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMaxSum() {
    for (int currIdx = 1; currIdx < N; currIdx++) {
        for (int prevIdx = 0; prevIdx < currIdx; prevIdx++) {
            if (seq[currIdx] <= seq[prevIdx]) continue;
            dp[currIdx] = max(dp[prevIdx] + seq[currIdx], dp[currIdx]);
        }
    }
    int mx = -1;
    for (int idx = 0; idx < N; idx++) {
        mx = max(mx, dp[idx]);
    }
    return mx;
}

int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        cin >> seq[idx];
        dp[idx] = seq[idx];
    }
    int ans = findMaxSum();
    cout << ans;
    return 0;
}