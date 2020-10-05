
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, less<int>> pq;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (!x) {
            int result;
            if (pq.empty()) {
                result = 0;
            }
            else {
                result = pq.top();
                pq.pop();
            }
            cout << result << "\n";
        }
        else {
            pq.push(x);
        }
    }
    return 0;
}