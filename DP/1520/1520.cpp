#include <iostream>
#include <cstring>
#define MAX 500
using namespace std;
int map[MAX][MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];
int M, N;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    memset(visited, 0, sizeof(visited));
}

int dfs(int y, int x) {
    if (y == 0 && x == 0) return 1;
    if (visited[y][x]) return dp[y][x];
    visited[y][x] = true;
    for (int idx = 0; idx < 4; idx++) {
        int ny = y + dy[idx];
        int nx = x + dx[idx];
        if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
        if (map[ny][nx] > map[y][x]) {
            dp[y][x] += dfs(ny ,nx);
        }
    }
    return dp[y][x];
}

int main() {
    init();
    cin >> M >> N;
    for (int row = 0; row < M; row++) {
        for (int col = 0; col < N; col++) {
            cin >> map[row][col];
            dp[row][col] = 0;
        }
    }
    int pathCnt = dfs(M - 1, N - 1);
    cout << pathCnt;
    return 0;
}