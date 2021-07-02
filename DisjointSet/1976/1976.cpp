#include <iostream>
#include <cstring>
#define MAX_NODE 200
#define MAX_DEST 1000
using namespace std;
int N, M;
int parent[MAX_NODE + 1];
int dest[MAX_DEST + 1];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    memset(parent, -1, sizeof(parent));
}

int find(int v) {
    for (; 0 < parent[v]; v = parent[v]);
    return v;
}

void merge(int v1, int v2) {
    int p1 = find(v1);
    int p2 = find(v2);
    if (p1 == p2) return;
    parent[p1] = p2;
}

int main() {
    init();
    cin >> N >> M;
    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= N; col++) {
            int connected;
            cin >> connected;
            if (connected) merge(row, col);
        }
    }

    for (int idx = 1; idx <= M; idx++) {
        cin >> dest[idx];
    }

    bool isConnected = true;
    for (int idx = 1; idx < M; idx++) {
        if (find(dest[idx]) != find(dest[idx + 1])) {
            isConnected = false;
            break;
        }
    }

    if (isConnected) cout << "YES";
    else cout << "NO";
    return 0;
}