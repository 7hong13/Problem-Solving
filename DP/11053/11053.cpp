#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arrA[1001];
int dp[1001];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

//Lis = LIS = Longest Increasing Subsequence
int findLis() {
    for (int currIdx = 1; currIdx < N; currIdx++) {
        for (int prevIdx = 0; prevIdx < currIdx; prevIdx++) {
            if (arrA[currIdx] <= arrA[prevIdx]) continue;
            dp[currIdx] = max(dp[currIdx], dp[prevIdx] + 1);
        }
    }
    int mx = -1;
    for (int idx = 0; idx < N; idx++) {
        mx = max(mx, dp[idx]);
    }
    return mx;
}

int main(){
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        cin >> arrA[idx];
        dp[idx] = 1;
    }
    int ans = findLis();
    cout << ans;
    return 0;
}