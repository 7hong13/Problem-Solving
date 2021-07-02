#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 500
using namespace std;
int n, m, maxVal = 0, area = 0;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    memset(visited, 0, sizeof(visited));
}

void dfs(int row, int col) {
    area++;
    for (int idx = 0; idx < 4; idx++) {
        int ny = row + dy[idx];
        int nx = col + dx[idx];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (map[ny][nx] && !visited[ny][nx]) {
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
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
                area = 0;
                dfs(row, col);
                cnt++;
                maxVal = max(maxVal, area);
            }
        }
    }
    cout << cnt << "\n" << maxVal;
    return 0;
}