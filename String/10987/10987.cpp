#include <iostream>
#include <cstring>
using namespace std;
int g_vowelCnt = 0;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    string word;
    cin >> word;
    char vowels[] = { 'a', 'i', 'u', 'e', 'o'};
    for (int idx = 0; idx < word.length(); idx++) {
        for (int vowel = 0; vowel < sizeof(vowels); vowel++) {
            if (word[idx] == vowels[vowel]) {
                g_vowelCnt++;
            }
        }
    }
    cout << g_vowelCnt << "\n";
    return 0;
}