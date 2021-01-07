#include <iostream>
using namespace std;
int dp[11];
void init() {   
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int countCases(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    if (dp[n]) return dp[n];
    return dp[n] = countCases(n - 1) + countCases(n - 2) + countCases(n - 3);
}

int main() {
    init();
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        int ans = countCases(n);
        cout << ans << "\n";
    }
    return 0;
}