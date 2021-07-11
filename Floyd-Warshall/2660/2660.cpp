#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 50
using namespace std;
int N;
int dp[MAX + 1][MAX + 1];
int mx[MAX + 1];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    fill(&dp[0][0], &dp[MAX][MAX + 1], MAX);
    fill(mx, mx + MAX + 1, -1);
}

void floyd() {
    for (int k = 1; k <= N; k++) {
        for (int u = 1; u <= N; u++) {
            for (int v = 1; v <= N; v++) {
                if (u == v) continue;
                dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);
            }
        }
    }
}

void printCandidatesInfo() {
    for (int u = 1; u <= N; u++) {
        for (int v = 1; v <= N; v++) {
            if (u == v) continue;
            mx[u] = max(mx[u], dp[u][v]);
        }
    }

    int mnVal = MAX;
    for (int u = 1; u <= N; u++) {
        mnVal = min(mnVal, mx[u]);
    }

    int cnt = 0;
    vector<int> candidates;
    for (int u = 1; u <= N; u++) {
        if (mx[u] == mnVal) {
            cnt++;
            candidates.push_back(u);
        }
    }

    cout << mnVal << ' ' << cnt << "\n";
    for (int idx = 0; idx < candidates.size(); idx++) {
        cout << candidates[idx] << ' ';
    }
}

int main() {
    init();
    cin >> N;
    int u, v;
    cin >> u >> v;
    while (u != -1 && v != -1) {
        dp[u][v] = min(dp[u][v], 1);
        dp[v][u] = min(dp[v][u], 1);
        cin >> u >> v;
    }
    floyd();
    printCandidatesInfo();
    return 0;
}