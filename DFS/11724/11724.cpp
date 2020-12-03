#include <iostream>
#include <vector>
using namespace std;
vector<int> adj_list[1002];
bool visited[1002];
int N, M, cnt = 0;
void dfs(int u) {
    visited[u] = true;
    for (int idx = 0; idx < adj_list[u].size(); idx++) {
        int v = adj_list[u][idx];
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for (int idx = 1; idx <= N; idx++) {
        if (!visited[idx]) {
            dfs(idx);
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}