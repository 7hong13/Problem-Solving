#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1000 
#define INF 999999999
using namespace std;
typedef pair<int, int> pii;
int N, M, dist[MAX + 1], dep, arr; //departure, arrival
vector<pii> graph[MAX + 1]; //destination, weight
priority_queue<pii, vector<pii>, greater<pii>> pq; //cost, destination
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    fill(dist, dist + MAX + 1, INF);
}

void dijkstra() {
    dist[dep] = 0;
    pq.push(pii(0, dep));
    while (!pq.empty()) {
        int minCost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (dist[u] < minCost) continue;
        for (pii v : graph[u]) {
            if (dist[v.first] <= dist[u] + v.second) continue;
            dist[v.first] = dist[u] + v.second;
            pq.push(pii(dist[v.first], v.first));
        }
    }
    cout << dist[arr];
}

int main() {
    init();
    cin >> N >> M;
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(pii(v, w));
    }
    cin >> dep >> arr;
    dijkstra();
    return 0;
}