#include <iostream>
#include <cstring>
using namespace std;
int N, cnt = 0, colorBlindCnt = 0;
char adjList[101][101];
char adjListForColorBlind[101][101];
bool visited[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
typedef pair<int, int> pii;
void dfs(pii u) {
    int x = u.first;
    int y = u.second;
    char color = adjList[x][y];
    visited[x][y] = true;
    for (int idx = 0; idx < 4; idx++) {
        int nx = x + dx[idx];
        int ny = y + dy[idx];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (color == adjList[nx][ny] && !visited[nx][ny]) {
            dfs(pii(nx, ny));
        }
    }
}

void dfsForColorBlind(pii u) {
    int x = u.first;
    int y = u.second;
    char color = adjListForColorBlind[x][y];
    visited[x][y] = true;
    for (int idx = 0; idx < 4; idx++) {
        int nx = x + dx[idx];
        int ny = y + dy[idx];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (color == adjListForColorBlind[nx][ny] && !visited[nx][ny]) {
            dfsForColorBlind(pii(nx, ny));
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> adjList[row][col];
            adjListForColorBlind[row][col] = 
                adjList[row][col] == 'G' ?  'R' : adjList[row][col];
        }
    }
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (!visited[row][col]) {
                dfs(pii(row, col));
                cnt++;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (!visited[row][col]) {
                dfsForColorBlind(pii(row, col));
                colorBlindCnt++;
            }
        }
    }
    cout << cnt << " " << colorBlindCnt << "\n";
    return 0;
}