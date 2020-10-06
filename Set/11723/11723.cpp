#include <iostream>
#include <string>
#include <set>
using namespace std;
set<int> s, all;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int m;
    cin >> m;
    for (int num = 1; num <= 20; num++) {
        all.insert(num);
    }
    while (m--) {
        string command;
        cin >> command;
        int item;
        if (command != "all" && command != "empty") {
            cin >> item;
        }
        if (command == "add") {
            s.insert(item);
        }
        else if (command == "remove") {
            s.erase(item);
        }
        else if (command == "check") {
            int result = s.find(item) == s.end() ? 0 : 1;
            cout << result << "\n";
        }
        else if (command == "toggle") {
            if (s.find(item) == s.end()) {
                s.insert(item);
            }
            else {
                s.erase(item);
            }
        }
        else if (command == "all") {
            s = all;
        }
        else if (command == "empty") {
            s.clear();
        }
    }
    return 0;
}