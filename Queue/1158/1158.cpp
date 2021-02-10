#include <iostream>
#include <queue>
using namespace std;
int N, K;
queue<int> q, ansQ;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void findPermutation() {
    for (int num = 1; num <= N; num++) {
        q.push(num);
    }
    int cnt = 0;
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        cnt++;
        if (cnt == K) {
            ansQ.push(num);
            cnt = 0;
            continue;
        }
        q.push(num);
    }
    cout << '<';
    while (ansQ.size() != 1) {
        cout << ansQ.front() << ", ";
        ansQ.pop();
    }
    cout << ansQ.front() << '>';
}

int main() {
    init();
    cin >> N >> K;
    findPermutation();
    return 0;
}