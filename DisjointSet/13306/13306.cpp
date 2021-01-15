#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
#define MAX 200000
int N, Q;
int parent[MAX + 1], backwardParent[MAX + 1];
int questions[2* MAX + 1][3];
stack<int> st;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    memset(parent, -1, sizeof(parent));
    memset(backwardParent, -1, sizeof(backwardParent));
}

int find(int v) {
    if (backwardParent[v] == -1) return v;
    return backwardParent[v] = find(backwardParent[v]);
}

void getInput() {
    for (int idx = 2; idx <= N; idx++) {
        cin >> parent[idx];
    }
    int cntDel, cntQ, idx;
    cntDel = cntQ = idx = 0;
    while (cntDel < N - 1 || cntQ < Q) {
        int x, b, c, d;
        cin >> x;
        if (x == 0) {
            cin >> b;
            questions[idx][0] = 0;
            questions[idx++][1] = b;
            cntDel++;
        }
        else {
            cin >> c >> d;
            questions[idx][0] = 1;
            questions[idx][1] = c;
            questions[idx++][2] = d;
            cntQ++;
        }
    }
}

bool doesPathExist(int u, int v) {
    int x = find(u);
    int y = find(v);
    if (x == y) return true;
    return false;
}

void printAnswer() {
    for (int idx = N - 2 + Q; idx >= 0; idx--) {
        if (questions[idx][0] == 0) {
            int v = questions[idx][1];
            backwardParent[v] = parent[v];
            continue;
        }
        int u = questions[idx][1];
        int v = questions[idx][2];
        if (doesPathExist(u, v)) st.push(1);
        else st.push(0);
    }
    while (!st.empty()) {
        string ans = st.top() == 1 ? "YES\n" : "NO\n";
        cout << ans;
        st.pop();
    }
}

int main() {
    init();
    cin >> N >> Q;
    getInput();
    printAnswer();
    return 0;
}