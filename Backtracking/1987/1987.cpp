#include <iostream>
using namespace std;
int R, C, mx = -1;
char board[21][21];
bool visited[26]; 
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void dfs(int y, int x, int cnt) {
    if (cnt > mx) {
        mx = cnt;
    }
    for (int idx = 0; idx < 4; idx++) {
        int ny = y + dy[idx];
        int nx = x + dx[idx];
        int transIdx = board[ny][nx] - 65;
        if (ny < 1 || ny > R || nx < 1 || nx > C) continue;
        if (visited[transIdx]) continue;
        visited[transIdx] = true;
        dfs(ny, nx, cnt + 1);
        visited[transIdx] = false;
    }
}

int main() {
    init();
    cin >> R >> C;
    for (int row = 1; row <= R; row++) {
        for (int col = 1; col <= C; col++) {
            cin >> board[row][col];
        }
    }
    int idx = board[1][1] - 65;
    visited[idx] = true;
    dfs(1, 1, 1);
    cout << mx;
    return 0;
}