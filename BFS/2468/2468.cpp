#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 100
using namespace std;
typedef pair<int, int> pii;
int N, safeZoneCnt = 1, minHght = 101, maxHght = -1;
int hghts[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void bfs(int y, int x) {
    queue<pii> q;
    q.push({y, x});
    while (!q.empty()) {
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();
        for (int idx = 0; idx < 4; idx++) {
            int ny = currY + dy[idx];
            int nx = currX + dx[idx];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (!visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

void findMaxZone() {
    int h = minHght;
    while (h < maxHght) {
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (hghts[row][col] <= h) visited[row][col] = true;
            }
        }
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (!visited[row][col]) {
                    visited[row][col] = true;
                    bfs(row, col);
                    cnt++;
                }
            }
        }
        h++;
        safeZoneCnt = max(safeZoneCnt, cnt);
    }
}

int main() {
    init();
    cin >> N;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> hghts[row][col];
            minHght = min(minHght, hghts[row][col]);
            maxHght = max(maxHght, hghts[row][col]);
        }
    }
    findMaxZone();
    cout << safeZoneCnt;
    return 0;
}