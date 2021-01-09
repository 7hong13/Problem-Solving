#include <iostream>
using namespace std;
int N, K;
int dp[1001][1001];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int calRemainder() {
    if (N == K || K == 0) return 1;
    if (K == 1 || N - K == 1) return N;
    for (int idx = 0; idx <= N; idx++) {
        dp[idx][0] = dp[idx][idx] =  1;
    }
    for (int row = 2; row < N; row++) {
        for (int col = 1; col < row; col++) {
            dp[row][col] = (dp[row - 1][col] + dp[row - 1][col - 1]) % 10007;
        }
    }
    for (int col = 1; col <= K; col++) {
        dp[N][col] = (dp[N - 1][col] + dp[N - 1][col - 1]) % 10007;
    }
    return dp[N][K];
}

int main() {
    init();
    cin >> N >> K;
    int ans = calRemainder();
    cout << ans;
    return 0;
}