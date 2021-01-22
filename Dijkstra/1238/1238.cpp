#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 1000
#define INF 999999
typedef pair<int, int> pii;
int dist[MAX + 1], N, M, X;
vector<pii> graph[MAX + 1]; //destination, cost
priority_queue<pii, vector<pii>, greater<pii>> pq; //cost, destination
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int dijstra(int start, int end) {
    if (start == end) return 0;
    dist[start] = 0;
    pq.push(pii(0, start));
    while (!pq.empty()) {
        int minCost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for (pii v : graph[u]) {
            if (dist[v.first] < minCost) continue;
            if (dist[v.first] <= dist[u] + v.second) continue;
            dist[v.first] = dist[u] + v.second;
            pq.push(pii(dist[v.first], v.first));
        }
    }
    return dist[end];
}

int main() {
    init();
    cin >> N >> M >> X;
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(pii(v, w));
    }
    int mx = -1;
    for (int start = 1; start <= N; start++) {
        fill(dist, dist + MAX + 1, INF);
        int go = dijstra(start, X);
        fill(dist, dist + MAX + 1, INF);
        int back = dijstra(X, start);
        mx = max(mx, go + back);
    }
    cout << mx;
    return 0;
}