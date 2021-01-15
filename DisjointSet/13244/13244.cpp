#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000
int T, N, M;
int parent[MAX + 1];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int find(int v) {
    for (; parent[v] > 0; v = parent[v]);
    return v;
}

void merge(int u, int v) {
    int x = find(u);
    int y = find(v);
    if (x == y) return;
    parent[x] = y;
}

bool isTree() {
    if (N - 1 != M) return false;
    int cnt = 0;
    for (int idx = 1; idx <= N; idx++) {
        if (parent[idx] == -1) cnt++;
    }
    if (cnt == 1) return true;
    return false;
}

int main() {
    init();
    cin >> T;
    while (T--) {
        memset(parent, -1, sizeof(parent));
        cin >> N >> M;
        for (int idx = 0; idx < M; idx++) {
            int u, v;
            cin >> u >> v;
            merge(u, v);
        }
        if (isTree()) cout << "tree\n";
        else cout << "graph\n";
    }
    return 0;
}