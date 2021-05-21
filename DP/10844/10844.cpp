#include <iostream>
#define MAX_N 100
using namespace std;
int N;
int dp[MAX_N + 1][10]; //0 ~ 9
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int countStairNumbers() {
    for (int idx = 1; idx < 10; idx++) {
        dp[1][idx] = 1;
    }
    for (int len = 2; len <= N; len++) {
        dp[len][0] = dp[len - 1][1]; 
        for (int idx = 1; idx < 9; idx++) {
            dp[len][idx] = (dp[len - 1][idx - 1] + dp[len - 1][idx + 1]) % 1000000000;
        }
        dp[len][9] = dp[len - 1][8];
    }
    long long sum = 0;
    for (int idx = 0; idx < 10; idx++) {
        sum += dp[N][idx];
    }
    return sum % 1000000000;
}

int main() {   
    init();
    cin >> N;
    int ans = countStairNumbers();
    cout << ans;
    return 0;
}