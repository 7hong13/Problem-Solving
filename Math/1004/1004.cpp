#include <iostream>
using namespace std;
int x1, y1, x2, y2, n;
int passTimeCnt = 0;
void countMinimumPassthrough(int n) {
    passTimeCnt = 0;
    while (n--) {
        int cx, cy, r;
        cin >> cx >> cy >> r;
        bool isDepartureInside, isArrivalInside;
        int distWithDeparture, distWithArrival;
        distWithDeparture = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy);
        distWithArrival = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy);
        isDepartureInside = distWithDeparture <= r * r ? true : false;
        isArrivalInside =  distWithArrival <= r * r ? true : false;
        if (isDepartureInside != isArrivalInside) {
            passTimeCnt++;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> x1 >> y1 >> x2 >> y2;
        int n;
        cin >> n;
        countMinimumPassthrough(n);
        cout << passTimeCnt << "\n";
    }
    return 0;
}