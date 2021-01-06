#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
const int MAX = 1000000 + 1;
int N;
int seq[MAX];
vector<ll> lis;
pair<int, int> answer[MAX];
stack<int> st;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void findLis() {
    lis.push_back(-9999999999);
    for (int idx = 0; idx < N; idx++) {
        int num = seq[idx];
        if (lis.back() < num) {
            lis.push_back(num);
            int index = lis.size() - 2; //-INF 제외
            answer[idx] = {index, num};
        }
        else {
            auto iter = lower_bound(lis.begin(), lis.end(), num);
            int index = lower_bound(lis.begin(), lis.end(), num) - lis.begin() - 1; //-INF 제외
            *iter = num;
            answer[idx] = {index, num};
        }
    }
    //-INF 제외 
    int size = lis.size() - 1;
    cout << size << "\n";
    int len = size - 1;
    for (int idx = N - 1; 0 <= idx ; idx--) {
        if (answer[idx].first == len) {
            st.push(answer[idx].second);
            len--;
        }
    }
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
}

int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        cin >> seq[idx];
    }
    findLis();
    return 0;
}