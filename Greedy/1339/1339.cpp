#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
int alphabets[26] = {0, };
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

bool comp(int num1, int num2) {
    return num1 > num2;
}

void calToNum(string word) {
    int len = word.length();
    int num = pow(10, len - 1);
    for (int idx = 0; idx < len; idx++) {
        int transIdx = word[idx] - 65;
        alphabets[transIdx] += num;
        num /= 10;
    }
}

int findMaxNum() {
    int num = 9, ans = 0;
    for (int idx = 0; alphabets[idx] != 0; idx++) {
        ans += alphabets[idx] * num;
        num--;
    }
    return ans;
}

int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        string word;
        cin >> word;
        calToNum(word);
    }
    sort(alphabets, alphabets + 26, comp);
    int ans = findMaxNum();
    cout << ans;
    return 0;
}