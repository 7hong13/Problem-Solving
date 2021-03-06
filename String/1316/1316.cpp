#include <iostream>
#include <cstring>
using namespace std;
bool isGroupWord(string word) {
    int alpahbets[26] = {0, };
    alpahbets[word[0] - 97]++;
    for (int idx = 1; idx < word.length(); idx++) {
        char current = word[idx];
        char prev = word[idx - 1];
        alpahbets[current - 97]++;
        if (current != prev && alpahbets[current - 97] > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int n;
    int groupWordNum = 0;
    cin >> n;
    while (n--) {
        string word;
        cin >> word;
        if (isGroupWord(word)) groupWordNum++;
    }
    cout << groupWordNum << "\n";
    return 0;
}
