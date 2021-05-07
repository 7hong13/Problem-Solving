#include <iostream>
#include <queue>
using namespace std;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findPrintOrder(int size, int pos) {
    int popCnt = 0;
    queue<int> q;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int idx = 0; idx < size; idx++) {
        int priority;
        cin >> priority;
        q.push(priority);
        pq.push(priority);
        if (idx == pos) q.push(-1);
    }
    while (!q.empty()) {
        int currPrio = q.front();
        int mxPrio = pq.top();
        if (currPrio < mxPrio) {
            q.push(currPrio);
            q.pop();
            continue;
        }
        q.pop();
        pq.pop();
        popCnt++;
        if (q.front() == -1) break;
    }
    return popCnt;
}

int main() {
    init();
    int T, N, M;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        int order = findPrintOrder(N, M);
        cout << order << "\n";
    }
    return 0;
}