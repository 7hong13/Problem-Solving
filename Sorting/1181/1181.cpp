#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool compare(string word1, string word2) {
    if (word1.length() == word2.length()) return word1 < word2;
    return word1.length() < word2.length();
}
string arrForSorting[20001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int idx = 0; idx < n; idx++) {
        cin >> arrForSorting[idx];
    }
    sort(arrForSorting, arrForSorting + n, compare);
    cout << arrForSorting[0] << "\n";
     for (int idx = 1; idx < n; idx++) {
         if (arrForSorting[idx-1] == arrForSorting[idx]) continue;
        cout << arrForSorting[idx] << "\n";
    }
    return 0;
}