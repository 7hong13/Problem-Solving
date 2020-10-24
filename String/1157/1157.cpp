#include <iostream>
#include <cstring>
using namespace std;
int alphabets[26] = {0, };
void countEachAlphabet(string word) {
    for (int idx = 0; idx < word.length(); idx++) {
        int charToInt;
        if (65 <= word[idx] && word[idx] <= 90) {
            charToInt = word[idx] - 65;
        }
        else {
            charToInt = word[idx] - 97;
        }
        alphabets[charToInt]++;
    }
}
int findMostUsedAlphabet() {
    int maxIndex = 0;
    for (int idx = 1; idx < 26; idx++) {
        if (alphabets[maxIndex] < alphabets[idx]) {
            maxIndex = idx;
        }
    }
    return maxIndex;
}
bool hasMultipleAnswer(int maxIndex) {
    int answerCnt = 0;
    for (int idx = 0; idx < 26; idx++) {
        if (alphabets[idx] == alphabets[maxIndex]) {
            answerCnt++;
            if (answerCnt > 1) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    string word;
    cin >> word;
    countEachAlphabet(word);
    int maxIndex = findMostUsedAlphabet();
    char answer = hasMultipleAnswer(maxIndex) ? '?' : maxIndex + 65;
    cout << answer << "\n";
    return 0;
}
