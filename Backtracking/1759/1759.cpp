#include <iostream>
#include <algorithm>
using namespace std;
int L, C;
char alphabets[16];
bool used[16];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

bool isVowel(char letter) {
    if (letter == 'a' || letter == 'e' || letter == 'i' 
        || letter == 'o' || letter == 'u') {
        return true;
    }
    return false;
}

void dfs(int start, int cnt) {
    if (cnt == L) {
        int cons = 0, vowel = 0;
        for (int idx = 0; idx < C; idx++) {
            if (used[idx]) {
                char letter = alphabets[idx];
                isVowel(letter) ? vowel++ : cons++;
            }
        }
        if (1 <= vowel && 2 <= cons) {
            for (int idx = 0; idx < C; idx++) {
                if (used[idx]) {
                    cout << alphabets[idx];
                }
            }
            cout << "\n";
        }
    }
    else {
        for (int idx = start + 1; idx < C; idx++) {
            used[idx] = true;
            dfs(idx, cnt + 1);
            used[idx] = false;
        }
    }
}

int main() {
    init();
    cin >> L >> C;
    for (int idx = 0; idx < C; idx++) {
        cin >> alphabets[idx];
    }
    sort(alphabets, alphabets + C);
    for (int start = 0; start < C - L + 1; start++) {
        used[start] = true;
        dfs(start, 1);
        used[start] = false;
    }
    return 0;
}