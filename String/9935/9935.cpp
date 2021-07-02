#include <iostream>
#include <string>
#define MAX 1000000
using namespace std;
string s, bomb;
char result[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void printResultStr() {
    int currIdx = 0;
    for (int idx = 0; idx < s.length(); idx++) {
        result[currIdx++] = s[idx];
        int bombSize = bomb.length();
        if (result[currIdx - 1] == bomb[bombSize - 1]) {
            if (currIdx - bombSize < 0) continue;
            bool detected = true;
            for (int bIdx = 0; bIdx < bombSize; bIdx++) {
                if (result[currIdx - bIdx - 1] != bomb[bombSize - bIdx - 1]) {
                    detected = false;
                    break;
                }
            }
            if (detected) currIdx -= bombSize;
        }
    }

    if (!currIdx) cout << "FRULA\n";
    else {
        for (int idx = 0; idx < currIdx; idx++) {
            cout << result[idx];
        }
    }
}

int main() {
    init();
    cin >> s >> bomb;
    printResultStr();
    return 0;
}