#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N, cnt = 0, cntForColorBlind = 0;
char adjList[101][101];
char adjListForColorBlind[101][101];
bool visited[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
typedef pair<int, int> pii;
void init() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void bfs(pii u) {
    queue<pii> q;
    q.push(u);
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        char color = adjList[x][y];
        q.pop();
        for (int idx = 0; idx < 4; idx++) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (!visited[nx][ny] && adjList[nx][ny] == color) {
                q.push(pii(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}

void bfsForColorBlind(pii u) {
    queue<pii> q;
    q.push(u);
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        char color = adjListForColorBlind[x][y];
        q.pop();
        for (int idx = 0; idx < 4; idx++) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (!visited[nx][ny] && adjListForColorBlind[nx][ny] == color) {
                q.push(pii(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    init();
    cin >> N;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> adjList[row][col];
            adjListForColorBlind[row][col] = adjList[row][col] == 'G' ?
                'R' : adjList[row][col];
        }
    }
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (!visited[row][col]) {
                visited[row][col] = true;
                bfs(pii(row, col));
                cnt++;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (!visited[row][col]) {
                visited[row][col] = true;
                bfsForColorBlind(pii(row, col));
                cntForColorBlind++;
            }
        }
    }
    cout << cnt << " " << cntForColorBlind << "\n";
    return 0;
}