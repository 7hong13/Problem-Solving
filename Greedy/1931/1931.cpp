#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 100000
using namespace std;
typedef pair<int, int> pii; //start, end
int N;
pii confTime[MAX];
vector<pii> endTimeList; //end, cnt
priority_queue<int, vector<int>, greater<int>> pq;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int countMaxConference() {
    sort(confTime, confTime + N);
    endTimeList.push_back(pii(confTime[0].first, 1));
    pq.push(confTime[0].first);
    for (int startIdx = 1; startIdx < N; startIdx++) {
        int start = confTime[startIdx].second;
        int end = confTime[startIdx].first;
        if (start < pq.top()) {
            endTimeList.push_back(pii(end, 1));
            pq.push(end);
            continue;
        }
        for (int idx = 0; idx < endTimeList.size(); idx++) {
            if (endTimeList[idx].first <= start) {
                endTimeList[idx].first = end;
                endTimeList[idx].second += 1;
                pq.pop();
                pq.push(end);
            }
        }
    }
    int mx = -1;
    for (int idx = 0; idx < endTimeList.size(); idx++) {
        mx = max(mx, endTimeList[idx].second);
    }
    return mx;
}

int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        int start, end;
        cin >> start >> end;
        confTime[idx] = pii(end, start);
    }
    int ans = countMaxConference();
    cout << ans;
    return 0;   
}