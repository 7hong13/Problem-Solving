#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100
#define INF 99999
int n, m, r;
int items[MAX + 1], dp[MAX + 1][MAX + 1];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void getInput() {
    cin >> n >> m >> r;
    for (int u = 1; u <= n; u++) {
        cin >> items[u];
        for (int v = 1; v <= n; v++) {
            dp[u][v] = INF;
        }
        dp[u][u] = 0;
    }
    while (r--) {
        int a, b, l;
        cin >> a >> b >> l;
        dp[a][b] = min(dp[a][b], l);
        dp[b][a] = min(dp[b][a], l);
    }
}

void setShortestPath() {
    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);
            }
        }
    }
}

int countMaxItems() {
    int mx = -1;
    for (int u = 1; u <= n; u++) {
        int sum = 0;
        for (int v = 1; v <= n; v++) {
            if (dp[u][v] <= m) sum += items[v];
        }
        mx = max(mx, sum);
    }
    return mx;
}

int main() {
    init();
    getInput();
    setShortestPath();
    int ans = countMaxItems();
    cout << ans;
    return 0;
}   