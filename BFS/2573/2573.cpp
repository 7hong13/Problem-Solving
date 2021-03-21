#include <iostream>
#include <queue>
#include <cstring>
#define MAX 300
using namespace std;
typedef pair<int, int> pii;
int N, M;
int area[MAX][MAX];
int iceToBeMelt[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void bfsForIceCnt(int y, int x) {
    queue<pii> q;
    q.push({y, x});
    visited[y][x] = true;
    while (!q.empty()) {
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();
        for (int idx = 0; idx < 4; idx++) {
            int ny = currY + dy[idx];
            int nx = currX + dx[idx];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (area[ny][nx] && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

void bfsForMelting() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (!area[row][col]) continue;
            int cnt = 0;
            for (int idx = 0; idx < 4; idx++) {
                int ny = row + dy[idx];
                int nx = col + dx[idx];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if (!area[ny][nx]) cnt++;
            }
            iceToBeMelt[row][col] = cnt;
        }
    }
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (!area[row][col]) continue;
            area[row][col] -= iceToBeMelt[row][col];
            if (area[row][col] < 0) area[row][col] = 0;
        }
    }
}

int countYears() {
    int yearCnt = 0;
    int iceCnt = 0;
    while (iceCnt < 2) {
        iceCnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                if (area[row][col] && !visited[row][col]) {
                    bfsForIceCnt(row, col);
                    iceCnt++;
                    if (iceCnt >= 2) return yearCnt;
                }
            }
        }
        if (iceCnt == 0) return 0;
        bfsForMelting();
        yearCnt++;
    }
    return 0;
}

int main() {
    init();
    cin >> N >> M;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> area[row][col];
        }
    }
    int ans = countYears();
    cout << ans;
    return 0;
}