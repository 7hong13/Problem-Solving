#include <iostream>
#define MAX 40
using namespace std;
int dp[MAX + 1];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    dp[0] = 0;
    dp[1] = 1;
}

int fibonacci(int n) {
    if (n == 0) return 0;
    if (dp[n]) return dp[n];
    return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n == 0) cout << "1 0\n";
        else if (n == 1) cout << "0 1\n";
        else {
            fibonacci(n);
            cout << dp[n - 1] << ' ' << dp[n] << "\n";
        }
    }
    return 0;
}