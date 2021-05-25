#include <iostream>
#include <queue>
#define MAX 100
using namespace std;
typedef pair<int, int> pii;
int map[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];
int M, N, K;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int bfs(int row, int col) {
    queue<pii> q;
    q.push(pii(row, col));
    int extent = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int idx = 0; idx < 4; idx++) {
            int ny = y + dy[idx];
            int nx = x + dx[idx];
            if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
            if (!visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push(pii(ny, nx));
                extent++;
            }
        }
    }
    return extent;
}

void drawRectangle(pii start, pii end) {
    for (int row = start.first; row < end.first; row++) {
        for (int col = start.second; col < end.second; col++) {
            visited[row][col] = true;
        }
    }
} 

void printAreasInfo() {
    int areaCnt = 0;
    priority_queue<int, vector<int>, greater<int> > pq; //넓이
    for (int row = 0; row < M; row++) {
        for (int col = 0; col < N; col++) {
            if (!visited[row][col]) {
                visited[row][col] = true;
                int extent = bfs(row, col);
                areaCnt++;
                pq.push(extent);
            }
        }
    }
    cout << areaCnt << "\n";
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
}

int main() {
    init();
    cin >> M >> N >> K;
    while (K--) {
        int startX, startY, endX, endY;
        cin >> startX >> startY >> endX >> endY;
        drawRectangle(pii(startY, startX), pii(endY, endX));
    }
    printAreasInfo();
    return 0;
}