#include <iostream>
#include <vector>
using namespace std;
vector<int> adj_list[101];
bool visited[101];
int cnt = 0;
void dfs(int v) {
    visited[v] = true;
    for (int idx = 0; idx < adj_list[v].size(); idx++) {
        if (!visited[adj_list[v][idx]]) {
            dfs(adj_list[v][idx]);
            cnt++;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    dfs(1);
    cout << cnt << "\n";
    return 0;
}