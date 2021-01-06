#include <iostream>
#include <algorithm>
using namespace std;
int seq[1001], N;
pair<int, int> dp[1001]; //first: up, second: down
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findLbs() {
    for (int currIdx = 1; currIdx < N; currIdx++) {
        for (int prevIdx = 0; prevIdx < currIdx; prevIdx++) {
            if (seq[prevIdx] < seq[currIdx]) {
                dp[currIdx].first = max(dp[currIdx].first, dp[prevIdx].first + 1);
            }
            else if (seq[prevIdx] > seq[currIdx]) {
                dp[currIdx].second = max(dp[currIdx].second, dp[prevIdx].second + 1);
                int mx = max(dp[prevIdx].first + 1, dp[prevIdx].second + 1);
                dp[currIdx].second = max(dp[currIdx].second, mx);
            }
        }
    }
    int mx = -1;
    for (int idx = 0; idx < N; idx++) {
        mx = max(mx, dp[idx].first);
        mx = max(mx, dp[idx].second);
    }
    return mx;
}

int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        cin >> seq[idx];
        dp[idx].first = 1;
        dp[idx].second = 1;
    }
    int ans = findLbs();
    cout << ans;
    return 0;
}