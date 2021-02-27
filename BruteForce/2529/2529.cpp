#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 9
using namespace std;
int k;
char signs[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

bool isValid(vector<int> nums) {
    int numIdx = 0;
    for (int idx = 0; idx < k; idx++) {
        char sign = signs[idx];
        int prevNum = nums[numIdx++];
        int currNum = nums[numIdx];
        if (sign == '<') {
            if (prevNum >= currNum) return false;
        }
        else if (sign == '>') {
            if (prevNum <= currNum) return false;
        }
    }
    return true;
}

string findMaxAnswer() {
    vector<int> maxNums;
    for (int num = 9; num > 9 - (k + 1); num--) {
        maxNums.push_back(num);
    } 
    while (!isValid(maxNums)) {
        prev_permutation(maxNums.begin(), maxNums.end());
    }
    string ans = "";
    for (int idx = 0; idx < maxNums.size(); idx++) {
        char num = maxNums[idx] + 48;
        ans += num;
    }
    return ans;
}

string findMinAnswer() {
    vector<int> minNums;
    for (int num = 0; num < k + 1; num++) {
        minNums.push_back(num);
    }
    while (!isValid(minNums)) {
        next_permutation(minNums.begin(), minNums.end());
    }
    string ans = "";
    for (int idx = 0; idx < minNums.size(); idx++) {
        char num = minNums[idx] + 48;
        ans += num;
    }
    return ans;
}

int main() {
    init();
    cin >> k;
    for (int idx = 0; idx < k; idx++) {
        cin >> signs[idx];
    }
    string maxAnswer = findMaxAnswer();
    string minAnswer = findMinAnswer();
    cout << maxAnswer << "\n" << minAnswer;
    return 0;
}