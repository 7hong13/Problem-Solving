#include <iostream>
#include <cstdlib>
#include <deque>
#include <cstring>
using namespace std;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void printAcResult() {
    deque<string> dq;
    int n;
    string order, arr;
    cin >> order;
    cin >> n;
    cin >> arr;
    string num = "";
    for (int idx = 1; idx < arr.size(); idx++) {
        if (n == 0) break;
        if (arr[idx] == ',' || arr[idx] == ']') {
            dq.push_back(num);
            num = "";
            continue;
        }
        num += arr[idx];
    }

    int begin = 0, end = n - 1;
    for (int idx = 0; idx < order.size(); idx++) {
        if (order[idx] == 'R') {
            int tmp = begin;
            begin = end;
            end = tmp;
            continue;
        }
        if (dq.empty()) {
            cout << "error\n";
            return;
        }
        if (begin <= end) {
            dq.pop_front();
            begin++;
        }
        else {
            dq.pop_back();
            end--;
        }
    }
    
    cout << '[';
    if (dq.empty()) {
        cout << "]\n";
        return;
    }
    while (dq.size() > 1) {
        if (begin <= end) {
            cout << dq.front() << ',';
            dq.pop_front();
        }
        else {
            cout << dq.back() << ',';
            dq.pop_back();
        }
    }
    cout << dq.front() << "]\n";
}

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        printAcResult();
    }
    return 0;
}