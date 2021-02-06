#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 125
#define INF 99999
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> coor;
int n, t = 1;
int dist[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int graph[MAX][MAX];
priority_queue<coor, vector<coor>, greater<coor>> pq;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void dijstra() {
    dist[0][0] = 0;
    pq.push(coor(graph[0][0], pii(0, 0)));
    while (!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        for (int idx = 0; idx < 4; idx++) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            int nw = cost + graph[nx][ny];
            if (nw < dist[nx][ny]) {
                dist[nx][ny] = nw;
                pq.push(coor(dist[nx][ny], pii(nx, ny)));
            }
        } 
    }
    cout << "Problem " << t << ": " << dist[n - 1][n - 1] << "\n";
}

int main() {
    init();
    cin >> n;
    while (n) {
        fill(&dist[0][0], &dist[MAX - 1][MAX], INF);
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                cin >> graph[row][col];
            }
        }
        dijstra();
        cin >> n;
        t++;
    }
    return 0;
}