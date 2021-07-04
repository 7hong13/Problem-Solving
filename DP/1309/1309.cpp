#include <iostream>
#define MAX 100000
using namespace std;
int dp[MAX + 1];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int countCases(int N) {
    dp[1] = 3;
    dp[2] = 7;
    for (int idx = 3; idx <= N; idx++) {
        dp[idx] = (2 * dp[idx - 1] + dp[idx - 2]) % 9901;
    }
    return dp[N];
}

int main() {
    init();
    int N;
    cin >> N;
    int ans = countCases(N);
    cout << ans;
    return 0;
}