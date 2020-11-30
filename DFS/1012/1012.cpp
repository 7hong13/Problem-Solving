#include <iostream>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
bool visited[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int M, N;
void dfs(pii coor) {
    int x, y;
    x = coor.first;
    y = coor.second;
    visited[x][y] = false;
    for (int idx = 0; idx < 4; idx++) {
        int nx = x + dx[idx];
        int ny = y + dy[idx];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) 
            continue;
        if (visited[nx][ny]) {
            dfs(pii(nx, ny));
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int T, K, cnt;
    cin >> T;
    while (T--) {
        cin >> M >> N >> K;
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        while (K--) {
            int X, Y;
            cin >> X >> Y;
            visited[X][Y] = true;
        }
        for (int x = 0; x < M; x++) {
            for (int y = 0; y < N; y++) {
                if (visited[x][y]) {
                    dfs(pii(x, y));
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}