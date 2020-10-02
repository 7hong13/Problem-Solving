#include <iostream>
#include <queue>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    while (testCase--) {
        int num, position, priority;
        cin >> num >> position;
        queue<int> q;
        priority_queue<int, vector<int>, less<int>> pq;
        for (int idx = 0; idx < num; idx++) {
            int priority;
            cin >> priority;
            q.push(priority);
            pq.push(priority); 
            if (idx == position) q.push(-1);
        }
        int popCnt = 0;
        while (!q.empty()) {
            int currPriority = q.front();
            if (currPriority < pq.top()) {
                q.pop();
                q.push(currPriority);
            }
            else {
                pq.pop();
                q.pop();
                popCnt++;
                if (q.front() == -1) break;
            }
        }
        cout << popCnt << "\n";
    }
    return 0;
}