#include <iostream>
#define MAX 30
using namespace std;
int dp[MAX][MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void setCases() {
    for (int num = 1; num < 30; num++) {
        dp[num][1] = num;
        dp[num][num] = 1;
    }
    for (int row = 3; row < 30; row++) {
        for (int col = 2; col < row; col++) {
            dp[row][col] = dp[row - 1][col - 1] + dp[row - 1][col];
        }
    }
}

int main() {
    init();
    int T;
    cin >> T;
    setCases();
    while (T--) {
        int N, M;
        cin >> N >> M;
        cout << dp[M][N] << "\n";
    }
    return 0;
}