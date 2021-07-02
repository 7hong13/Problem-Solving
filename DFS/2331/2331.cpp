#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#define MAX 1000000
using namespace std;
string A;
int P;
int pos[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    memset(pos, 0, sizeof(pos));
}

void dfs(string curr, int cnt) {
    if (pos[stoi(curr)]) {
        cout << pos[stoi(curr)] - 1;
        return;
    }
    pos[stoi(curr)] = cnt;
    string next;
    int sum = 0;
    for (int idx = 0; idx < curr.size(); idx++) {
        int num = curr[idx] - 48;
        sum += pow(num, P);
    }
    next = to_string(sum);
    dfs(next, cnt + 1);
}

int main() {
    init();
    cin >> A >> P;
    dfs(A, 1);
    return 0;
}