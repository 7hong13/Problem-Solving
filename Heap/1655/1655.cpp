#include <iostream>
#include <queue>
using namespace std;
int N, med;
priority_queue<int, vector<int>, less<int>> smaller;
priority_queue<int, vector<int>, greater<int>> bigger;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void findMedium() {
    cin >> med;
    cout << med << "\n";
    N--;
    while (N--) {
        int num;
        cin >> num;
        if (med < num) {
            bigger.push(num);
            if (smaller.size() + 1 < bigger.size()) {
                smaller.push(med);
                med = bigger.top();
                bigger.pop();
            }
        }
        else {
            smaller.push(num);
            if (bigger.size() < smaller.size()) {
                bigger.push(med);
                med = smaller.top();
                smaller.pop();
            }
        }
        cout << med << "\n";
    }
}

int main() {
    init();
    cin >> N;
    findMedium();
    return 0;
}