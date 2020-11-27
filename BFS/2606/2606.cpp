#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj_list[101];
queue<int> q;
bool visited[101];
int cnt = 0;
void bfs() {
   q.push(1);
   visited[1] = true;
   while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (int v : adj_list[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            q.push(v);
        }
   }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    bfs();
    cout << --cnt << "\n";
    return 0;
}