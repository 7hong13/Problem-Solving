#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAX 50
#define INF 99999999
using namespace std;
typedef pair<int, int> pii;
int N, M, minDist = INF;
vector<pii> chick, house;
bool chickUsed[13];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int calDist(pii x1, pii x2) {
    return abs(x1.first - x2.first) + abs(x1.second - x2.second);
}

void dfs(int start, int cnt) {
    if (cnt == M) {
        int houseDist[2 * MAX];
        fill(houseDist, houseDist + 2 * MAX, INF);
        for (int idx = 0; idx < chick.size(); idx++) {
            if (!chickUsed[idx]) continue;
            for (int subIdx = 0; subIdx < house.size(); subIdx++) {
               int dist = calDist(chick[idx], house[subIdx]);
               houseDist[subIdx] = min(houseDist[subIdx], dist);
            }
        }
        int sum = 0;
        for (int idx = 0; idx < house.size(); idx++) {
            sum += houseDist[idx];
        }
        minDist = min(minDist, sum);
        return;
    }
    for (int idx = start; idx < chick.size(); idx++) {
        chickUsed[idx] = true;
        dfs(idx + 1, cnt + 1);
        chickUsed[idx] = false;
    }
}

int main() {
    init();
    cin >> N >> M;
    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= N; col++) {
            int num;
            cin >> num;
            if (num == 1) house.push_back(pii(row, col));
            if (num == 2) chick.push_back(pii(row, col));
        }
    }
    dfs(0, 0);
    cout << minDist;
    return 0;
}