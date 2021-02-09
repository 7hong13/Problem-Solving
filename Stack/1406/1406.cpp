#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<char> tmpSt;
stack<char> ansSt;
int M;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void findEditedStr() {
    while (M--) {
        char order;
        cin >> order;
        if (order == 'L' && !tmpSt.empty()) {
            ansSt.push(tmpSt.top());
            tmpSt.pop();
        }
        else if (order == 'D' && !ansSt.empty()) {
            tmpSt.push(ansSt.top());
            ansSt.pop();
        }
        else if (order == 'B' && !tmpSt.empty()) {
            tmpSt.pop();
        }
        else if (order == 'P') {
            char newChar;
            cin >> newChar;
            tmpSt.push(newChar);
        }
    }
    while (!tmpSt.empty()) {
        ansSt.push(tmpSt.top());
        tmpSt.pop();
    }
    while (!ansSt.empty()) {
        cout << ansSt.top();
        ansSt.pop();
    }
}

int main() {
    init();
    string s;
    cin >> s;
    for (int idx = 0; idx < s.size(); idx++) {
        tmpSt.push(s[idx]);
    }
    cin >> M;
    findEditedStr();
    return 0;
}