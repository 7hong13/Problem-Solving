#include <iostream>
#include <queue>
using namespace std;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findNthLargestNum(int n) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            int num;
            cin >> num;
            if (pq.size() < n) pq.push(num);
            else if (pq.top() < num) {
                pq.pop();
                pq.push(num);
            }
        }
    }
    return pq.top();
}

int main() {
    init();
    int n;
    cin >> n;
    int ans = findNthLargestNum(n);
    cout << ans;
    return 0;
}