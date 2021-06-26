#include <iostream>
#include <queue>
#define MAX_SIZE 250
using namespace std;
typedef pair<int, int> pii;
bool visited[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE];
int R, C;
int sheepCnt, wolfCnt;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void bfs(int row, int col) {
    queue<pii> q;
    q.push(pii(row, col));
    int tmpSheep, tmpWolf;
    tmpSheep = tmpWolf = 0;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (map[y][x] == 'v') tmpWolf++;
        else if (map[y][x] == 'o') tmpSheep++;
        for (int idx = 0; idx < 4; idx++) {
            int ny = y + dy[idx];
            int nx = x + dx[idx];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if (!visited[ny][nx] && map[ny][nx] != '#') {
                q.push(pii(ny, nx));
                visited[ny][nx] = true;
            } 
        }
    }
    if (tmpSheep == 0 && tmpWolf == 0) return;
    tmpWolf < tmpSheep ? sheepCnt += tmpSheep : wolfCnt += tmpWolf;
}  

int main() {
    init();
    sheepCnt = wolfCnt = 0;
    cin >> R >> C;
    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cin >> map[row][col];
        }
    }
    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            if (!visited[row][col] && map[row][col] != '#') {
                visited[row][col] = true;
                bfs(row, col);
            }
        }
    }
    cout << sheepCnt << ' ' << wolfCnt;
    return 0;
}