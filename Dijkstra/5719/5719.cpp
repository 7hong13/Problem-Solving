#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 500
#define INF 999999
typedef pair<int, int> pii;
int N, M, S, D, dist[MAX];
priority_queue<pii, vector<pii>, greater<pii>> pq; //cost, destination
bool visited[MAX][MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int dijkstra(vector<pii> graph[], vector<int> path[]) {
    fill(dist, dist + MAX, INF);
    dist[S] = 0;
    pq.push(pii(0, S));
    while (!pq.empty()) {
        int minCost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for (pii v : graph[u]) {
            if (visited[u][v.first]) continue;
            if (dist[v.first] < minCost) continue;
            if (dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                pq.push(pii(dist[v.first], v.first));
                path[v.first].clear();
                path[v.first].push_back(u);
            }
            //최단 거리가 여러 개 일 수 있으므로
            else if (dist[v.first] == dist[u] + v.second) { 
                //1 -> 2 이면 2 -> 1로 값 입력
                path[v.first].push_back(u);
            }
        }
    }
    return dist[D];
}

void bfsForErasingPath(vector<int> path[]) {
    queue<int> q;
    q.push(D);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : path[u]) {
            //path[u] -> v = graph[v] -> u
            //path 상 2 -> 1 일 경우, 실제 graph에서 1 -> 2 의미
            if (visited[v][u]) continue;
            visited[v][u] = true;
            q.push(v);
        }
    }
}

int main() {
    init();
    cin >> N >> M;
    while (N != 0 && M != 0) {
        cin >> S >> D;
        memset(visited, 0, sizeof(visited));
        vector<pii> graph[MAX]; //destination, cost
        vector<int> path[MAX];
        while (M--) {
            int U, V, P;
            cin >> U >> V >> P;
            graph[U].push_back(pii(V, P));
        }
        int firstMinCost = dijkstra(graph, path);
        bfsForErasingPath(path);
        int afterMinCost = dijkstra(graph, path);
        int ans = afterMinCost == INF ? -1 : afterMinCost;
        cout << ans << "\n";
        cin >> N >> M;
    }
    return 0;
}