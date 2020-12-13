#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, string> pis;
int T, input, target, d1, d2, d3, d4;
bool visited[10000];
void init() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void calRegisterNum(int result) {
    d1 = result / 1000;
    result %= 1000;
    d2 = result / 100;
    result %= 100;
    d3 = result / 10;
    result %= 10;
    d4 = result;
}

void bfs() {
    queue<pis> q;
    q.push(pis(input, ""));
    visited[input] = true;
    while (!q.empty()) {
        int resultNum = q.front().first;
        string resultStr = q.front().second;
        q.pop();
        if (resultNum == target) {
            cout << resultStr << "\n";
            return;
        }
        calRegisterNum(resultNum);
        int caseD = resultNum * 2 > 9999 
            ? (resultNum * 2) % 10000 : resultNum * 2;
        int caseS = resultNum == 0 ? 9999 : resultNum - 1;
        int caseL = d2 * 1000 + d3 * 100 + d4 * 10 + d1;
        int caseR = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
        int numList[] = {caseD, caseS, caseL, caseR};
        char charList[] = {'D', 'S', 'L', 'R'};
        for (int idx = 0; idx < 4; idx++) {
            int num = numList[idx];
            if (!visited[num]) {
                q.push(pis(num, resultStr + charList[idx]));
                visited[num] = true;
            }
        }
    }
}

int main() {
    init();
    cin >> T;
    while (T--) {
        cin >> input >> target;
        memset(visited, 0, sizeof(visited));
        bfs();
    }
    return 0;
}