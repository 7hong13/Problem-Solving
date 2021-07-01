#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int N;
int names[26];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void printFirstNames() {
    memset(names, 0, sizeof(names));
    while (N--) {
        string name;
        cin >> name;
        names[name[0] - 97]++;
    }
    
    bool hasNoTeam = true;
    for (int idx = 0; idx < 26; idx++) {
        if (names[idx] >= 5) {
            hasNoTeam = false;
            char letter = idx + 97;
            cout << letter;
        }
    }
    if (hasNoTeam) cout << "PREDAJA";
}

int main() {
    init();
    cin >> N;
    printFirstNames();
    return 0;
}