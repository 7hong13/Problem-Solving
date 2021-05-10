#include <iostream>
#include <algorithm>
#define MAX 300
using namespace std;
int n;
int dp[MAX];
int arr[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMaxSum() {
    dp[1] += dp[0];
    dp[2] += max(dp[0], arr[1]);
    for (int idx = 2; idx < n; idx++) {
        dp[idx] = max(dp[idx - 2], dp[idx - 3] + arr[idx - 1]) + arr[idx];
    }
    return dp[n - 1];
}

int main() {
    init();
    cin >> n;
    for (int idx = 0; idx < n; idx++) {
        cin >> arr[idx];
        dp[idx] = arr[idx];
    }
    int ans = findMaxSum();
    cout << ans;
    return 0;
}