#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj_list[1002];
bool visited[1002];
int N, M, cnt;
void bfs(int n) {
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int idx = 0; idx < adj_list[u].size(); idx++) {
            int v = adj_list[u][idx];
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
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
            visited[idx] = true;
            bfs(idx);
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}