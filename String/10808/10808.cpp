#include <iostream>
#include <cstring>
using namespace std;
int alphabets[26] = {0, };

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    string word;
    cin >> word;
    for (int letterNum = 0; letterNum < word.length(); letterNum++) {
        int charToInt = word[letterNum] - 97;
        alphabets[charToInt]++;
    }
    for (int idx = 0; idx < 26; idx++) {
        cout << alphabets[idx] << " ";
    }
    cout << "\n";
    return 0;
}