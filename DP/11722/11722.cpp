#include <iostream>
#include <algorithm>
using namespace std;
int seq[1001], dp[1001], N;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findLds() {
    for (int currIdx = 1; currIdx < N; currIdx++) {
        for (int prevIdx = 0; prevIdx < currIdx; prevIdx++) {
            if (seq[prevIdx] <= seq[currIdx]) continue;
            dp[currIdx] = max(dp[currIdx], dp[prevIdx] + 1);
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
        dp[idx] = 1;
    }
    int ans = findLds();
    cout << ans;
    return 0;
}