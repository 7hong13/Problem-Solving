#include <iostream>
#include <queue>
#define MAX 1000000
using namespace std;
typedef pair<int, int> pii;
bool visited[MAX + 1]; //idx starts from 1
int F, S, G, U, D;
int minCnt = -1;
queue<pii> q; //floor, buttonCount
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

bool isValidFloor(int f) {
    if (f > F || f < 1) return false;
    return true;
} 

void bfs() {
    q.push({S, 0});
    visited[S] = true;
    while (!q.empty()) {
        int curr = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (curr == G) {
            minCnt = cnt;
            return;
        }
        int floors[2] = {curr + U, curr - D};
        for (int idx = 0; idx < 2; idx++) {
            int floor = floors[idx];
            if (isValidFloor(floor) && !visited[floor]) {
                visited[floor] = true;
                q.push({floor, cnt + 1});
            } 
        }
    }
}

int main() {
    init();
    cin >> F >> S >> G >> U >> D;
    bfs();
    minCnt == -1 ? cout << "use the stairs" : cout << minCnt;
    return 0;
}