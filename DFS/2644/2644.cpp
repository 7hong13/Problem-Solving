#include <iostream>
#include <vector>
#define MAX 100 
using namespace std;
int n, u, v, ans = -1;
vector<int> adjList[MAX];
bool visited[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void dfs(int x, int cnt) {
    visited[x] = true;
    if (x == u) {
        ans = cnt;
        return;
    }
    for (int idx = 0; idx < adjList[x].size(); idx++) {
        int node = adjList[x][idx];
        if (!visited[node]) {
            dfs(node, cnt + 1);
        }
    }
}

int main() {
    init();
    cin >> n;
    int m;
    cin >> v >> u >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    dfs(v, 0);
    cout << ans << "\n";
    return 0;
}