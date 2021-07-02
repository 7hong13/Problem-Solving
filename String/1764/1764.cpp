#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
vector<string> combined;
vector<string> common;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void printPeopleInCommon() {
    sort(combined.begin(), combined.end());
    for (int idx = 0; idx < N + M - 1; idx++) {
        if (combined[idx] == combined[idx + 1]) common.push_back(combined[idx]);
    }
    cout << common.size() << "\n";
    for (int idx = 0; idx < common.size(); idx++) {
        cout << common[idx] << "\n";
    }
}

int main() {
    init();
    cin >> N >> M;
    for (int idx = 0; idx < N + M; idx++) {
        string s;
        cin >> s;
        combined.push_back(s);
    }
    printPeopleInCommon();
    return 0;
}