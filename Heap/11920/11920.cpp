#include <iostream>
#include <queue>
using namespace std;
int N, K;
priority_queue<int, vector<int>, greater<int>> pq;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void bubbleSort() {
    for (int idx = 0; idx < N; idx++) {
        int num;
        cin >> num;
        if (pq.size() < K) {
            pq.push(num);
            continue;
        }
        if (num > pq.top()) {
            cout << pq.top() << ' ';
            pq.pop();
            pq.push(num);
        }
        else {
            cout << num << ' ';
        }
    }
    while (!pq.empty()) {
        cout << pq.top() << ' '; 
        pq.pop();
    }
}

int main() {
    init();
    cin >> N >> K;
    bubbleSort();
    return 0;
}