#include <iostream>
#include <queue>
#include <cmath>
#define MAX_TOWN_NUM 4000 
#define MAX_DISTANCE 10000 //max distance = 8485.xxx
#define MAX_COOR_VALUE 6000 //0, 1~3000(양수), 3001~6000(음수)
#define INF 999999999
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> coor;
int X1, Y1, X2, Y2, N;
pii towns[MAX_TOWN_NUM + 1]; //include X2, Y2
int dist[MAX_COOR_VALUE + 1][MAX_COOR_VALUE + 1]; //include 0
bool isPrimeNum[MAX_DISTANCE];
priority_queue<coor, vector<coor>, greater<coor>> pq;
void findPrimeNum() {
    isPrimeNum[0] = isPrimeNum[1] = false;
    for (int num = 2; num * num < MAX_DISTANCE; num++) {
        if (isPrimeNum[num]) {
            for (int sieve = num * num; sieve < MAX_DISTANCE; sieve += num) {
                if (isPrimeNum[sieve]) isPrimeNum[sieve] = false;
            }
        }
    }
}

void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    fill(&dist[0][0], &dist[MAX_COOR_VALUE][MAX_COOR_VALUE + 1], INF);
    fill(isPrimeNum, isPrimeNum + 10000, 1);
    findPrimeNum();
}

int transIdx(int idx) {
    if (0 <= idx) return idx;
    return idx * -1 + 3000;
}

int dijstra() {
    dist[transIdx(X1)][transIdx(Y1)] = 0;
    pq.push(coor(0, pii(X1, Y1)));
    while (!pq.empty()) {
        int totalDist = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        for (int idx = 0; idx <= N; idx++) {
            int nx = towns[idx].first;
            int ny = towns[idx].second;
            int currDist = (int) sqrt((x - nx) * (x - nx) + (y - ny) * (y - ny));
            if (isPrimeNum[currDist] && currDist + totalDist < dist[transIdx(nx)][transIdx(ny)]) {
                dist[transIdx(nx)][transIdx(ny)] = currDist + totalDist;
                pq.push(coor(currDist + totalDist, pii(nx, ny)));
            }
        }
    }
    return dist[transIdx(X2)][transIdx(Y2)] == INF ? -1 : dist[transIdx(X2)][transIdx(Y2)];
}

int main() {
    init();
    cin >> X1 >> Y1 >> X2 >> Y2 >> N;
    towns[0] = pii(X2, Y2);
    for (int idx = 1; idx <= N; idx++) {
        int X3, Y3;
        cin >> X3 >> Y3;
        towns[idx] = pii(X3, Y3);
    }
    int minDist = dijstra();
    cout << minDist;
    return 0;
}