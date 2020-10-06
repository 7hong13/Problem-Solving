#include <iostream>
#include <deque>
#include <string>
using namespace std;
deque<int> dq;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        string command;
        cin >> command;
        if (command == "push_front") {
            int item;
            cin >> item;
            dq.push_front(item);
        }
        else if (command == "push_back") {
            int item;
            cin >> item;
            dq.push_back(item);
        }
        else if (command == "pop_front") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (command == "pop_back") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (command == "size") {
            cout << dq.size() << "\n";
        }
        else if (command == "empty") {
            dq.empty() ? cout << "1\n" : cout << "0\n";
        }
        else if (command == "front") {
            dq.empty() ? cout << "-1\n" : cout << dq.front() << "\n";
        }
         else if (command == "back") {
            dq.empty() ? cout << "-1\n" : cout << dq.back() << "\n";
        }
    }
    return 0;
}