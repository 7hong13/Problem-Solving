#include <iostream>
#include <algorithm>
#define MAX 100000
#define INF 99999
using namespace std;
int dp[MAX];
int arr[MAX];
int n;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMaxSum() {
    for (int idx = 1; idx < n; idx++) {
        dp[idx] = max(dp[idx - 1] + arr[idx], arr[idx]);
    }
    int mx = -INF;
    for (int idx = 0; idx < n; idx++) {
        mx = max(mx, dp[idx]);
    }
    return mx;
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