#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000
int N, M;
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

int findConnectedComponents() {
    int cnt = 0;
    for (int idx = 1; idx <= N; idx++) {
        if (parent[idx] == -1) cnt++;
    }
    return cnt;
}

int main() {
    init();
    cin >> N >> M;
    memset(parent, -1, sizeof(parent));
    while (M--) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    int ans = findConnectedComponents();
    cout << ans;
    return 0;
}