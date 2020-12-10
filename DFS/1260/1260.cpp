#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, V;
vector<int> adjList[1001];
bool visited[1001];
void init() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int idx = 0; idx < adjList[u].size(); idx++) {
        int v = adjList[u][idx];
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int idx = 0; idx < adjList[u].size(); idx++) {
            int v = adjList[u][idx];
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}
int main() {
    init();
    cin >> N >> M >> V;
    while (M--) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (int idx = 0; idx < N; idx++) {
        sort(adjList[idx].begin(), adjList[idx].end());
    }
    dfs(V);
    memset(visited, 0, sizeof(visited));
    cout << "\n";
    bfs(V);
    return 0;
}