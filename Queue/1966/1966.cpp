#include <iostream>
#include <queue>
using namespace std;
int findPrintOrder(int num, int position) {
    queue<int> q;
    priority_queue<int, vector<int>, less<int>> pq;
    //set priority sequence
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
    return popCnt;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int testCase;
    cin >> testCase;
    while (testCase--) {
        int num, position, priority;
        cin >> num >> position;
        int popCnt = findPrintOrder(num, position);
        cout << popCnt << "\n";
    }
    return 0;
}