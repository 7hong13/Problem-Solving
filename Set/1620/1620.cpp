#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<string, int> monInfo;
string monNames[100002];
monInfo totalInfo[100002];
void makePocketmonList(int n) {
    for (int idx = 0; idx < n; idx++) {
        string name;
        cin >> name;
        //for index input
        monNames[idx] = name;
        monInfo mon;
        mon.first = name;
        mon.second = idx;
        //for pocketmon name input
        totalInfo[idx] = mon;
    }
}
void findPocketmon(int m, int n) {
    while (m--) {
        string question;
        cin >> question;
        if (48 <= question[0] && question[0] <= 57) {
            int num = atoi(question.c_str());
            cout << monNames[num - 1] << "\n";
        }
        else {
            int low = 0, high = n - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (totalInfo[mid].first == question) {
                    cout << totalInfo[mid].second + 1 << "\n";
                    break;
                }
                else if (totalInfo[mid].first > question) {
                    high = mid -1;
                }
                else {
                    low = mid + 1;
                }
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    makePocketmonList(n);
    //For binary search
    sort(totalInfo, totalInfo + n);
    findPocketmon(m, n);
    return 0;
}