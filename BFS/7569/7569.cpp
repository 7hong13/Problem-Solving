#include <iostream>
#include <queue>
#define MAX 100
using namespace std;
struct position {
    int x;
    int y;
    int h;
};
int M, N, H, day = 0;
int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dh[] = {0, 0, 0, 0, 1, -1};
int boxes[MAX][MAX][MAX];
queue<position> q;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void bfs() {
    int size = q.size();
    int checkCnt = 0;
    while (!q.empty()) {
        if (checkCnt == size) {
            day++;
            size = q.size();
            checkCnt = 0;
        } 
        int x = q.front().x;
        int y = q.front().y;
        int h = q.front().h;
        q.pop();
        checkCnt++;
        for (int idx = 0; idx < 6; idx++) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            int nh = h + dh[idx];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M
                || nh < 0 || nh >= H) continue;
            if (boxes[nx][ny][nh] == 0) {
                q.push({nx, ny, nh});
                boxes[nx][ny][nh] = 1;
            }
        }
    }
}

int main() {
    init();
    cin >> M >> N >> H;
    for (int hgt = 0; hgt < H; hgt++) {
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                cin >> boxes[row][col][hgt];
                if (boxes[row][col][hgt] == 1) q.push({row, col, hgt});
            }
        }
    }
    bfs();
    for (int hgt = 0; hgt < H; hgt++) {
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                if (boxes[row][col][hgt] == 0) {
                    day = -1;
                    break;
                }
            }
        }
    }
    cout << day;
    return 0;
}