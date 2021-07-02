#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 500
using namespace std;
typedef pair<int, int> pii;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, maxVal = 0;
int map[MAX][MAX];
bool visited[MAX][MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    memset(visited, 0, sizeof(visited));
}

void bfs(int row, int col) {
    queue<pii> q;
    q.push(pii(row, col));
    int cnt = 0;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        cnt++;
        for (int idx = 0; idx < 4; idx++) {
            int ny = y + dy[idx];
            int nx = x + dx[idx];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (!visited[ny][nx] && map[ny][nx]) {
                visited[ny][nx] = true;
                q.push(pii(ny, nx));
            }
        }
    }
    maxVal = max(cnt, maxVal);
}
int main() {
    init();
    cin >> n >> m;
    int cnt = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> map[row][col];
        }
    }
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (!visited[row][col] && map[row][col]) {
                visited[row][col] = true;
                bfs(row, col);
                cnt++;
            }
        }
    }
    cout << cnt << "\n" << maxVal;
    return 0;
}