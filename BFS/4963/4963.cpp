#include <iostream>
#include <queue>
#include <cstring>
#define MAX 50
using namespace std;
typedef pair<int, int> pii;
bool visited[MAX][MAX];
int map[MAX][MAX];
int w, h;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void bfs(int row, int col) {
    queue<pii> q;
    q.push(pii(row, col));
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int idx = 0; idx < 8; idx++) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (map[ny][nx] && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push(pii(ny, nx));
            }
        }
    }
}

int main() {
    init();
    cin >> w >> h;
    while (w != 0 && h != 0) {
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int row = 0; row < h; row++) {
            for (int col = 0; col < w; col++) {
                cin >> map[row][col];
            }
        }
        for (int row = 0; row < h; row++) {
            for (int col = 0; col < w; col++) {
                if (map[row][col] && !visited[row][col]) {
                    visited[row][col] = true;
                    bfs(row, col);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
        cin >> w >> h;
    }
    return 0;
}