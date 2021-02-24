#include <iostream>
#define MAX 1000
using namespace std;
int dp[MAX + 1];
int n;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    dp[1] = 1;
    dp[2] = 2;
}

int countTilingCases(int n) {
    if (dp[n]) return dp[n];
    return dp[n] = (countTilingCases(n - 1) + countTilingCases(n - 2)) % 10007;
}

int main() {
    init();
    cin >> n;
    int ans = countTilingCases(n);
    cout << ans;
    return 0;
}