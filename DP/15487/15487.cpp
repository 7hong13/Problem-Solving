#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 1000001
#define INF 999999999
int arr[MAX], N;
int dp1[MAX], dp2[MAX]; //dp1: start from left, dp2: start from right
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMaxValue() {
    int mn = arr[0];
    dp1[1] = arr[1] - arr[0];
    for (int j = 2; j < N - 2; j++) {
        mn = min(mn, arr[j - 1]);
        dp1[j] = max(dp1[j - 1], arr[j] - mn);
    }
    int mx = arr[N - 1];
    for (int k = N - 2; k > 1; k--) {
        mx = max(mx, arr[k + 1]);
        dp2[k] = max(mx - arr[k], dp2[k + 1]);
    }
    mx = -999999999;
    for (int idx = 1; idx < N - 2; idx++) {
        mx = max(dp1[idx] + dp2[idx + 1], mx);
    }
    return mx;
}

int main() {   
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        cin >> arr[idx];
        dp1[idx] = dp2[idx] = -999999999;
    }
    int ans = findMaxValue();
    cout << ans;
    return 0;
}