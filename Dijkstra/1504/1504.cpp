#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 800
#define INF 99999999
using namespace std;
typedef pair<int, int> pii;
int dist[MAX + 1];
int N, E, v1, v2;
vector<pii> graph[MAX + 1]; //destination, cost
priority_queue<pii, vector<pii>, greater<pii>> pq; //cost, destination
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int dijstra(int start, int end) {
    fill(dist, dist + MAX + 1, INF);
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
    cin >> N >> E;
    while (E--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(pii(b, c));
        graph[b].push_back(pii(a, c));
    }
    cin >> v1 >> v2;
    int ans1 = dijstra(1, v1) + dijstra(v1, v2) + dijstra(v2, N);
    int ans2 = dijstra(1, v2) + dijstra(v2, v1) + dijstra(v1, N);
    int minAns = min(ans1, ans2);
    if (INF <= minAns) cout << "-1";
    else cout << minAns;
    return 0;
}