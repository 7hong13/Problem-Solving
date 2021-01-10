#include <iostream>
#include <cstring>
using namespace std;
int nums[101];
typedef long long ll;
ll dp[21][101];
int N;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

ll countCases() {
    dp[nums[0]][0] = 1;
    //N - 2까지만 계산
    for (int idx = 1; idx < N - 1; idx++) {
        int num = nums[idx];
        for (int prevNum = 0; prevNum <= 20; prevNum++) {
            if (!dp[prevNum][idx - 1]) continue;
            int sum = prevNum + num;
            int diff = prevNum - num;
            if (0 <= sum && sum <= 20) dp[sum][idx] += dp[prevNum][idx - 1];
            if (0 <= diff && diff <= 20) dp[diff][idx] += dp[prevNum][idx - 1];
        }
    }
    int lastNum = nums[N - 1];
    return dp[lastNum][N - 2];
}

int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        cin >> nums[idx];
    }
    memset(dp, 0, sizeof(dp));
    ll ans = countCases();
    cout << ans;
    return 0;
}