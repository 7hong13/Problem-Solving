#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MAX 1000
#define INF 999999999
typedef pair<int, int> pii;
int n, m, dist[MAX + 1], nearest[MAX + 1];
vector<pii> graph[MAX + 1];
priority_queue<pii, vector<pii>, greater<pii>> pq;
stack<int> path;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    fill(dist, dist + MAX + 1, INF);
}

int dijstra(int start, int end) {
    dist[start] = 0;
    pq.push(pii(0, start));
    while (!pq.empty()) {
        int minCost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (dist[u] < minCost) continue;
        for (pii v : graph[u]) {
            if (dist[v.first] <= dist[u] + v.second) continue;
            dist[v.first] = dist[u] + v.second;
            pq.push(pii(dist[v.first], v.first));
            nearest[v.first] = u;
        }
    }
    return dist[end];
}

void printSizeAndPath(int end) {
    int v = end;
    while (v) {
        path.push(v);
        v = nearest[v];
    }
    cout << path.size() << "\n";
    while (!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }
    cout << "\n";
}

int main() {
    init();
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(pii(v, w));
    }
    int start, end;
    cin >> start >> end;
    int cost = dijstra(start, end);
    cout << cost << "\n";
    printSizeAndPath(end);
    return 0;
}