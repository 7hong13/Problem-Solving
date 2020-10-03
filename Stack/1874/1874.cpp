#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack<int> st;
queue<char> q;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int num = 1;
    st.push(num++);
    q.push('+');
    bool isImpossible = false;
    while (n--) {
        int sequenceNum;
        cin >> sequenceNum;
        if (st.empty()) {
            st.push(num++);
            q.push('+');
        }
        if (st.top() > sequenceNum) {
            isImpossible = true;
        }
        while (st.top() < sequenceNum) {
            st.push(num++);
            q.push('+');
        } 
        st.pop();
        q.push('-');
    }
    if (isImpossible) {
        cout << "NO\n";
    }
    else {
        while (!q.empty()) {
            cout << q.front() << "\n";
            q.pop();
        }
    }
    return 0;
}