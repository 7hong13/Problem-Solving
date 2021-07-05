#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

string find1stWordInDict(string word) {
    vector<string> words;
    string tmp;
    for (int start = 1; start < word.length() - 1; start++) {
        for (int mid = start + 1; mid < word.length(); mid++) {
            string ans;
            tmp = word.substr(0, start);
            reverse(tmp.begin(), tmp.end());
            ans += tmp;

            tmp = word.substr(start, mid - start);
            reverse(tmp.begin(), tmp.end());
            ans += tmp;

            tmp = word.substr(mid, word.length() - 1);
            reverse(tmp.begin(), tmp.end());
            ans += tmp;

            words.push_back(ans);
        }
    }
    sort(words.begin(), words.end());
    return words[0];
}

int main() {
    init();
    string word;
    cin >> word;
    string ans = find1stWordInDict(word);
    cout << ans;
    return 0;
}
