#include <iostream>
#include <cstring>
#include <queue>
#define MAX 100
using namespace std;
struct coor {
    int x;
    int y;
    int cnt;
};
int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void bfs(int row, int col) {
    queue<coor> q;
    q.push(coor{col, row, 1});
    visited[row][col] = true;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();
        if (x == M - 1 && y == N - 1) {
            cout << cnt;
            return;
        }
        for (int idx = 0; idx < 4; idx++) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (map[ny][nx] == 1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push(coor{nx, ny, cnt + 1});
            }
        }
    }
}

int main() {
    init();
    cin >> N >> M;
    for (int row = 0; row < N; row++) {
        string s;
        cin >> s;
        for (int col = 0; col < M; col++) {
            map[row][col] = s[col] - 48;
        }
    }
    bfs(0, 0);
    return 0;
}