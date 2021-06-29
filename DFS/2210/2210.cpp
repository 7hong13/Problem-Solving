#include <iostream>
#include <set>
using namespace std;
int map[5][5];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
set<int> s;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void dfs(int y, int x, int cnt, int sum) {
    if (cnt == 6) {
        s.insert(sum);
        return;
    }
    for (int idx = 0; idx < 4; idx++) {
        int nx = x + dx[idx];
        int ny = y + dy[idx];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        dfs(ny, nx, cnt + 1, sum * 10 + map[ny][nx]);
    }
}

int main() {
    init();
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            cin >> map[row][col];
        }
    }
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            dfs(row, col, 1, map[row][col]);
        }
    }
    cout << s.size();
    return 0;
}