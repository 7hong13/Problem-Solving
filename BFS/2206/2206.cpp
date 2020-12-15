#include <iostream>
#include <queue>
#include <string>
using namespace std;
int N, M, routeCnt = 2;
int adjList[1001][1001];
bool visited[1001][1001][2];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
typedef pair<int, int> pii;
typedef pair<pii, pii> routeAndCnt;
void init() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int bfs() {
    pii startPoint = pii(1, 1);
    pii totalAndWallCnt = pii(1, 0);
    queue<routeAndCnt> q;
    q.push(routeAndCnt(startPoint, totalAndWallCnt));
    while (!q.empty()) {
        pii coor = q.front().first;
        pii cnt = q.front().second;
        q.pop();
        int y = coor.first;
        int x = coor.second;
        int totalCnt = cnt.first;
        int wallCnt = cnt.second;
        if (y == N && x == M) {
            return totalCnt;
        }
        for (int idx = 0; idx < 4; idx++) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (ny < 1 || ny > N || nx < 1 || nx > M) 
                continue;
            if (!visited[ny][nx][1] && adjList[ny][nx] == 1 && wallCnt < 1) {
                q.push(routeAndCnt(pii(ny, nx), pii(totalCnt + 1, wallCnt + 1)));
                visited[ny][nx][1] = true;
            }
            else if (!visited[ny][nx][0] && adjList[ny][nx] == 0 && wallCnt < 1) {
                q.push(routeAndCnt(pii(ny, nx), pii(totalCnt + 1, wallCnt)));
                visited[ny][nx][0] = true;
            }
            else if (!visited[ny][nx][1] && adjList[ny][nx] == 0 && wallCnt == 1) {
                q.push(routeAndCnt(pii(ny, nx), pii(totalCnt + 1, wallCnt)));
                visited[ny][nx][1] = true;
            }
        }
    }
    return -1;
}

int main() {
    init();
    cin >> N >> M;
    for (int row = 1; row <= N; row++) {
        string s;
        cin >> s;
        for (int col = 1; col <= M; col++) {
            adjList[row][col] = s[col - 1] - 48;
        }
    }
    visited[1][1][0] = true;
    routeCnt = bfs();
    cout << routeCnt << "\n";
    return 0;
}