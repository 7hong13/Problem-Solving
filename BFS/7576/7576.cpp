#include <iostream>
#include <queue>
using namespace std;
int M, N, popCnt = 0, day = 0;
typedef pair<int, int> pii;
queue<pii> q;
int adjList[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void init() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void bfs() {
    int size = q.size();
    while (!q.empty()) {
        if (size == popCnt) {
            day++;
            popCnt = 0;
            size = q.size();
        }
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        popCnt++;
        for (int idx = 0; idx < 4; idx++) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (adjList[nx][ny] == 0) {
                adjList[nx][ny] = 1;
                q.push(pii(nx, ny));
            }
        }
    }
}

int main() {
    init();
    cin >> M >> N;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> adjList[row][col];
            if (adjList[row][col] == 1) {
                q.push(pii(row, col));
            }
        }
    }
    bfs();
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (adjList[row][col] == 0) {
                day = -1;
            }
        }
    }
    cout << day << "\n";
    return 0;
}