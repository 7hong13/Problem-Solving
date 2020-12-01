#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> adj_list[101];
int dist[101] = {0, };
int N;
int bfs(int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj_list[u]) {
            if (dist[v] > 0) continue;
            if (v == start) continue;
            dist[v] = 1 + dist[u];
            q.push(v);
        }
    }
    int sum = 0;
    for (int idx = 1; idx <= N; idx++) {
        sum += dist[idx];
    }
    return sum;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int M, min = 99999999, ans = -1;
    cin >> N >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for (int idx = 1; idx <= N; idx++) {
        memset(dist, 0, sizeof(dist));
        int sum = bfs(idx);
        if (sum < min) {
            min = sum;
            ans = idx;
        }
    }
    cout << ans << "\n";
    return 0;
}