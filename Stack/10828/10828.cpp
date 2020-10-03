#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
stack<int> st;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        string command;
        cin >> command;
        if (command == "push") {
            int item;
            cin >> item;
            st.push(item);
        }
        else if (command == "top") {
            int result = st.empty() ? -1 : st.top();
            cout << result << "\n";
        }
        else if (command == "size") {
            cout << st.size() << "\n";
        }
        else if (command == "empty") {
            int result = st.empty() ? 1 : 0;
            cout << result << "\n";
        }
        else if (command == "pop") {
            if (st.empty()) {
                cout << "-1\n";
            }
            else {
                cout << st.top() << "\n";
                st.pop();
            }
        }
    }
    return 0;
}