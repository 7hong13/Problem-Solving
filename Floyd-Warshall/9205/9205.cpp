#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 100
#define INF 999999999
typedef pair<int, int> pii;
int t, n, dp[MAX + 2][MAX + 2];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int calDist(pii u, pii v) {
    int x1 = u.first, y1 = u.second;
    int x2 = v.first, y2 = v.second;
    int dist = abs(x1 - x2) + abs(y1 - y2);
    return dist;
}

int floyd(vector<pii> coor) {
    fill(&dp[0][0], &dp[MAX][MAX + 1], INF);
    for (int u = 0; u < n + 2; u++) {
        for (int v = 0; v < n + 2; v++) {
            if (u == v) continue;
            int dist = calDist(coor[u], coor[v]);
            if (dist <= 1000) {
                dp[u][v] = 1;
            }
        }
    }
    for (int k = 0; k < n + 2; k++) {
        for (int u = 0; u < n + 2; u++) {
            for (int v = 0; v < n + 2; v++) {
                dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);
            }
        }
    }
    return dp[0][n + 1];
}

int main() {
    init();
    cin >> t;
    while (t--) {
        cin >> n;
        int x, y;
        cin >> x >> y; //집
        vector<pii> coor;
        coor.push_back(pii(x, y));
        for (int iter = 0; iter < n; iter++) {
            cin >> x >> y; //편의점
            coor.push_back(pii(x, y));
        }
        cin >> x >> y; //도착지
        coor.push_back(pii(x, y));
        int ans = floyd(coor);
        if (ans == INF) cout << "sad\n";
        else cout << "happy\n";
    }
    return 0;
}