#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
int cheese[101][101];
bool visited[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int H, W, hour = 0, cheeseCnt = 0, lastCheeseCnt; 
void init() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void bfsForAirChecking(pii start) {
    queue<pii> q;
    q.push(start);
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second; 
        q.pop();
        for (int idx = 0; idx < 4; idx++) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if (!visited[ny][nx] && cheese[ny][nx] == 0) {
                q.push(pii(ny, nx));
                visited[ny][nx] = true;
            }
        }
    }
}

void bfsForMelting(pii start) {
    int y = start.first;
    int x = start.second;
    for (int idx = 0; idx < 4; idx++) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (visited[ny][nx]) {
                cheese[y][x] = 0;
                cheeseCnt--;
                return;
            }
    }
}

int main() {
    init();
    cin >> H >> W;
    for (int row = 0; row < H; row++) {
        for (int col = 0; col < W; col++) {
            cin >> cheese[row][col];
            if (cheese[row][col] == 1) cheeseCnt++;
        }
    }
    while (cheeseCnt > 0) {
        lastCheeseCnt = cheeseCnt;
        memset(visited, 0, sizeof(visited));
        visited[0][0] = true;
        bfsForAirChecking(pii(0, 0));
        for (int row = 1; row < H - 1; row++) {
            for (int col = 1; col < W - 1; col++) {
                if (cheese[row][col] == 1) {
                    bfsForMelting(pii(row, col));
                }
            }
        }
        hour++;
    }
    cout << hour << "\n" << lastCheeseCnt << "\n";
    return 0;
}