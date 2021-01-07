#include <iostream>
using namespace std;
long long dp[101];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

long long padovanSeq(int n) {
    if (n == 1 || n == 2 || n == 3) return dp[n] = 1;
    if (dp[n]) return dp[n];
    return dp[n] = padovanSeq(n - 2) + padovanSeq(n - 3);
}

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        long long pn = padovanSeq(N);
        cout << pn << "\n";
    }
    return 0;
}