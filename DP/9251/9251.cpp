#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1001][1001];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findLcs(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    memset(dp, 0, sizeof(dp));
    for (int idx1 = 1; idx1 <= n1; idx1++) {
        for (int idx2 = 1; idx2 <= n2; idx2++) {
            if (s1[idx1 - 1] == s2[idx2 - 1]) {
                dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1] + 1;
            }
            else {
                dp[idx1][idx2] = max(dp[idx1][idx2 - 1], dp[idx1 - 1][idx2]);
            }
        }
    }
    return dp[n1][n2];
}

int main() {
    init();
    string s1, s2;
    cin >> s1 >> s2;
    int ans = findLcs(s1, s2);
    cout << ans;
    return 0;
}