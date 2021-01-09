#include <iostream>
using namespace std;
int n, k;
int value[101], dp[100001] = {0, };
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int countCases() {
    dp[0] = 1;
    for (int idx = 0; idx < n; idx++) {
        int val = value[idx];
        for (int cost = val; cost <= k; cost++) {
            dp[cost] += dp[cost - val];
        }
    }
    return dp[k];
}

int main() {
    init();
    cin >> n >> k;
    for (int idx = 0; idx < n; idx++) {
        cin >> value[idx];
    }
    int ans = countCases();
    cout << ans;
    return 0;
}