#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1000
using namespace std;
typedef pair<int, int> pii;
struct pos {
    int x;
    int y;
    int cnt;
};
char map[MAX][MAX];
bool visited[MAX][MAX];
int t, w, h;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int bfs(int x, int y, queue<pii> fire) {
    queue<pos> q;
    q.push(pos{x, y, 0});
    visited[y][x] = true;
    while (!q.empty()) {
        int size = fire.size();
        for (int iter = 0; iter < size; iter++) {
            int currX = fire.front().first;
            int currY = fire.front().second;
            fire.pop();
            for (int idx = 0; idx < 4; idx++) {
                int nx = currX + dx[idx];
                int ny = currY + dy[idx];
                if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                if (map[ny][nx] == '.') {
                    map[ny][nx] = '*';
                    fire.push(pii(nx, ny));
                }
            }
        }
        size = q.size();
        for (int iter = 0; iter < size; iter++) {
            int currX = q.front().x;
            int currY = q.front().y;
            int cnt = q.front().cnt;
            q.pop();
            if (currX == 0 || currY == 0 || currX == w - 1 || currY == h - 1) return cnt + 1;
            for (int idx = 0; idx < 4; idx++) {
                int nx = currX + dx[idx];
                int ny = currY + dy[idx];
                if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                if (!visited[ny][nx] && map[ny][nx] == '.') {
                    visited[ny][nx] = true;
                    q.push(pos{nx, ny, cnt + 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    init();
    cin >> t;
    while (t--) {
        cin >> w >> h;
        queue<pii> fire;
        int x, y;
        memset(visited, 0, sizeof(visited));
        for (int row = 0; row < h; row++) {
            for (int col = 0; col < w; col++) {
                cin >> map[row][col];
                if (map[row][col] == '@') {
                    x = col;
                    y = row;
                    map[row][col] = '.';
                }
                else if (map[row][col] == '*') {
                    fire.push(pii(col, row));
                }
            }
        }
        int ans = bfs(x, y, fire);
        ans == -1 ? cout << "IMPOSSIBLE\n" : cout << ans << "\n";
    }
    return 0;
}