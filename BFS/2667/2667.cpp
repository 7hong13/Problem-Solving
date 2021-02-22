#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 25
using namespace std;
typedef pair<int, int> pii;
int N, map[MAX][MAX], totalComplexNum = 0;
bool visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> complexNums;
queue<pii> q;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void bfs(pii start) {
    int cnt = 0;
    q.push(pii(start.first, start.second));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cnt++;
        for (int idx = 0; idx < 4; idx++) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (map[nx][ny] && !visited[nx][ny]) {
                q.push(pii(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
    complexNums.push_back(cnt);
}

void printComplexNums() {
    sort(complexNums.begin(), complexNums.end());
    cout << totalComplexNum << "\n";
    for (int idx = 0; idx < complexNums.size(); idx++) {
        cout << complexNums[idx] << "\n";
    }
}

int main() {   
    init();
    cin >> N;
    for (int row = 0; row < N; row++) {
        string s;
        cin >> s;
        for (int col = 0; col < N; col++) {
            map[row][col] = s[col] - 48;
        }
    }
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (map[row][col] && !visited[row][col]) {
                visited[row][col] = true;
                bfs(pii(row, col));
                totalComplexNum++;
            }
        }
    }
    printComplexNums();
    return 0;
}