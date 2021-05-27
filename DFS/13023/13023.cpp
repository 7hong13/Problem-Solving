#include <iostream>
#include <vector>
#include <cstring>
#define MAX 2000
using namespace std;
int N, M;
vector<int> adjList[MAX];
bool visited[MAX];
bool doesExist;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void dfs(int v, int cnt) {
    if (cnt == 5) {
        doesExist = true;
        return;
    }
    visited[v] = true;
    for (int idx = 0; idx < adjList[v].size(); idx++) {
        int u = adjList[v][idx];
        if (!visited[u]) {
            visited[u] = true;
            dfs(u, cnt + 1);
        }
    }
    visited[v] = false;
}

void checkRelationship() {
    for (int idx = 0; idx < N; idx++) {
        doesExist = false;
        memset(visited, 0, sizeof(visited));
        dfs(idx, 1);
        if (doesExist) break;
    }
}

int main() {
    init();
    cin >> N >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    checkRelationship();
    doesExist ? cout << "1\n" : cout << "0\n";
    return 0;
}