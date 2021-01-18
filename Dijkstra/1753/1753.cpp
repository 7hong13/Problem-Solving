#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 99999999
#define MAX 20000
typedef pair<int, int> pii;
int V, E, K;
int dist[MAX + 1];
vector<pii> graph[MAX + 1]; //destination, weight
priority_queue<pii, vector<pii>, greater<pii>> pq; //cost, destination
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    fill(dist, dist + MAX + 1, INF);
}

void dijkstra() {
    pq.push(pii(0, K));
    while (!pq.empty()) {
        int minDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (dist[u] < minDist) continue;
        for (pii v : graph[u]) {
            if (dist[v.first] <= dist[u] + v.second) continue;
            dist[v.first] = dist[u] + v.second;
            pq.push(pii(dist[v.first], v.first));
        }
    }
    for (int u = 1; u <= V; u++) {
        if (dist[u] == INF) cout << "INF\n";
        else if (u == K) cout << "0\n";
        else cout << dist[u] << "\n";
    }
}

int main() {
    init();
    cin >> V >> E >> K;
    dist[K] = 0;
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(pii(v, w));
    }
    dijkstra();
    return 0;
}