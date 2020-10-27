#include <iostream>
#include <cstring>
using namespace std;
int g_vowelCnt = 0;
char vowels[] = { 'a', 'i', 'u', 'e', 'o'};
void countVowels(string word) {
    for (int idx = 0; idx < word.length(); idx++) {
        for (int vowel = 0; vowel < sizeof(vowels); vowel++) {
            if (word[idx] == vowels[vowel]) {
                g_vowelCnt++;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    string word;
    cin >> word;
    countVowels(word);
    cout << g_vowelCnt << "\n";
    return 0;
}