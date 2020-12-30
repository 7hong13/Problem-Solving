#include <iostream>
using namespace std;
typedef long long ll;
int n;
ll dp[1001];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int tiling(int n) {
    if (dp[n]) return dp[n];
    if (n == 1) return 1;
    if (n == 2) return 3;
    return dp[n] = (tiling(n - 1) + 2 * tiling(n - 2)) % 10007;
}

int main() {
    init();
    cin >> n;
    int ans = tiling(n);
    cout << ans;
    return 0;
}