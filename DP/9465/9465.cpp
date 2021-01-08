#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[2][100001];
int score[2][100001];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMaxScore(int n) {
    memset(dp, 0, sizeof(dp));
    dp[0][1] = score[0][1];
    dp[1][1] = score[1][1];
    for (int idx = 2; idx <= n; idx++) {
        dp[0][idx] = max(dp[1][idx - 1], dp[1][idx - 2]) + score[0][idx];
        dp[1][idx] = max(dp[0][idx - 1], dp[0][idx - 2]) + score[1][idx];
    }
    return max(dp[0][n], dp[1][n]);
}

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int idx = 1; idx <= n; idx++) {
            cin >> score[0][idx];
        }
        for (int idx = 1; idx <= n; idx++) {
            cin >> score[1][idx];
        }
        int ans = findMaxScore(n);
        cout << ans << "\n";
    } 
    return 0;
}