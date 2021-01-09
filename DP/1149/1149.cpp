#include <iostream>
#include <algorithm>
using namespace std;
int N;
int cost[1001][3];
int dp[1001][3];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMinCost() {
    for (int idx = 0; idx < 3; idx++) {
        dp[0][idx] = cost[0][idx];
    }
    for (int idx = 1; idx < N; idx++) {
        dp[idx][0] = min(dp[idx - 1][1], dp[idx - 1][2]) + cost[idx][0];
        dp[idx][1] = min(dp[idx - 1][0], dp[idx - 1][2]) + cost[idx][1];
        dp[idx][2] = min(dp[idx - 1][0], dp[idx - 1][1]) + cost[idx][2];
    }
    int mx = min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
    return mx;
}

int main() {
    init();  
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        for (int subIdx = 0; subIdx < 3; subIdx++) {
            cin >> cost[idx][subIdx];
        }
    }
    int ans = findMinCost();
    cout << ans;
    return 0;
}