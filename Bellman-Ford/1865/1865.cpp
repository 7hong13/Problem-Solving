#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 500
#define INF 999999999
typedef pair<int, int> pii; //destination, cost
int TC, N, M, W;
int dist[MAX + 1];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

bool canReverseTime(vector<pii> graph[]) {
    dist[1] = 0;
    for (int check = 1; check <= N - 1; check++) {
        for (int u = 1; u <= N; u++) {
            for (pii v : graph[u]) {
                dist[v.first] = min(dist[v.first], dist[u] + v.second);
            }
        }
    }

    bool hasMinusCycle = false;
    for (int u = 1; u <= N; u++) {
        for (pii v : graph[u]) {
            if (dist[v.first] > dist[u] + v.second) {
                hasMinusCycle = true;
                break;
            }
        }
        if (hasMinusCycle) break;
    }
    return hasMinusCycle;
}

int main() {
    init();
    cin >> TC;
    while (TC--) {
        cin >> N >> M >> W;
        int u, v, cost;
        fill(dist, dist + MAX + 1, INF);
        vector<pii> graph[MAX + 1];
        for (int iter = 0; iter < M; iter++) {
            cin >> u >> v >> cost;
            graph[u].push_back(pii(v, cost));
            graph[v].push_back(pii(u, cost));
        }
        for (int iter = 0; iter < W; iter++) {
            cin >> u >> v >> cost;
            graph[u].push_back(pii(v, cost * -1));
        }
        if (canReverseTime(graph)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}