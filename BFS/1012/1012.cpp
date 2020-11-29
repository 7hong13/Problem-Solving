#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
bool visited[51][51];
int M, N;
int dx[] = {-1 , 0, 1, 0};
int dy[] = {0, -1, 0, 1};
void bfs(pii coor) {
    queue<pii> q;
    q.push(coor);
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int idx = 0; idx < 4; idx++) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (visited[nx][ny]) {
                q.push(pii(nx, ny));
                visited[nx][ny] = false;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int T, K, X, Y;
    cin >> T;
    while (T--) {
        int cnt = 0;
        cin >> M >> N >> K;
        memset(visited, 0, sizeof(visited));
        while (K--) {
            cin >> X >> Y;
            visited[X][Y] = true;
        }
        for (int x = 0; x < M; x++) {
            for (int y = 0; y < N; y++) {
                if (visited[x][y]) {
                    visited[x][y] = false;
                    bfs(pii(x, y));
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}