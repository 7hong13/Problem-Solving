#include <iostream>
#include <algorithm>
using namespace std;
#define INF 999999999
#define MAX 100
int n, m, dp[MAX + 1][MAX + 1];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    fill(&dp[0][0], &dp[MAX][MAX + 1], INF);
}

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);
            }
        }
    }
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (dp[u][v] == INF) cout << "0 ";
            else cout << dp[u][v] << ' ';
        }
        cout << "\n";
    }
}

int main() {
    init();
    cin >> n >> m;
    for (int u = 1; u <= n; u++) {
        dp[u][u] = 0;
    }
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = min(dp[u][v], w);
    }
    floyd();
    return 0;
}