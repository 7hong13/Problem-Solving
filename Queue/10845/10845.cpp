#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
queue<int> q;

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
            q.push(item);
        }
        else if (command == "front") {
            int result = q.empty() ? -1 : q.front();
            cout << result << "\n";
        }
        else if (command == "back") {
           int result = q.empty() ? -1 : q.back();
            cout << result << "\n";
        }
        else if (command == "size") {
            cout << q.size() << "\n";
        }
        else if (command == "empty") {
            int result = q.empty() ? 1 : 0;
            cout << result << "\n";
        }
        else if (command == "pop") {
            if (q.empty()) {
                cout << "-1\n";
            }
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
    }
    return 0;
}