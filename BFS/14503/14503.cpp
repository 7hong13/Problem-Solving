#include <iostream>
#include <queue>
#define MAX 50
using namespace std;
typedef pair<int, int> pii;
int room[MAX][MAX];
int N, M, currR, currC, currD, cnt = 1;
int dx[] = {-1, 0, 1, 0, -1, 0, 1};
int dy[] = {0, 1, 0, -1, 0, 1, 0};
//북:0, 동:1, 남:2, 서:3
queue<pii> q;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

bool isInvalidPos(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= M) return true;
    return false;
} 
void bfs() {
    q.push(pii(currR, currC));
    room[currR][currC] = 2;
    while (!q.empty()) {
        currR = q.front().first;
        currC = q.front().second;
        q.pop();
        bool hasRoom = false;
        for (int idx = currD; idx < currD + 4; idx++) {
            int leftR = currR + dy[idx];
            int leftC = currC + dx[idx];
            if (isInvalidPos(leftR, leftC)) continue;
            if (room[leftR][leftC] == 0) {
                q.push(pii(leftR, leftC));
                room[leftR][leftC] = 2;
                currD = (idx + 1) % 4;
                cnt++;
                hasRoom = true;
                break;
            }
        }
        if (hasRoom) continue;
        int rearR = currR + dy[currD + 1];
        int rearC = currC + dx[currD + 1];
        if (isInvalidPos(rearR, rearC) || room[rearR][rearC] == 1) return;
        q.push(pii(rearR, rearC));
    }
}

int main() {
    init();
    cin >> N >> M;
    cin >> currR >> currC >> currD;
    if (currD == 1) currD = 3;
    else if (currD == 3) currD = 1;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> room[row][col];
        }
    }
    bfs();
    cout << cnt;
    return 0;   
}