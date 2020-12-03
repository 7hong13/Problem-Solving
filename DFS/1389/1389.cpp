#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N, M;
int dist[101];
int start;
vector<int> adj_list[101];
void dfs(int v) {
    for (int idx = 0; idx < adj_list[v].size(); idx++) {
        int u = adj_list[v][idx];
        if (u == start) continue;
        if (dist[u] > 0) {
            if (dist[u] < dist[v] + 1) continue;
        }
        dist[u] = dist[v] + 1;
        dfs(u);
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int min = 999999999, ans = -1;
    cin >> N >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for (int idx = 1; idx <= N; idx++) {
        memset(dist, 0, sizeof(dist));
        start = idx;
        dfs(idx);
        int sum = 0;
        for (int value = 1; value <= N; value++){
            sum += dist[value];
        }
        if (sum < min) {
            min = sum;
            ans = idx;
        }
    }
    cout << ans << "\n";
    return 0;
}