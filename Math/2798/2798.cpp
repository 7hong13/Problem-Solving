#include <iostream>
#include <cmath>
using namespace std;
int cards[300001];
int n, m;
int findTheClosestNum() {
    int sum = -999999999;
    for (int card1 = 0; card1 < n - 2; card1++) {
        for (int card2 = card1 + 1; card2 < n - 1; card2++) {
            for (int card3 = card2 + 1; card3 < n; card3++) {
                int tempSum = cards[card1] + cards[card2] + cards[card3];
                int diff1 = abs(sum - m);
                int diff2 = abs(tempSum - m);
                if (tempSum <= m && diff2 < diff1) {
                    sum = cards[card1] + cards[card2] + cards[card3];
                }
            }
        }
    }
    return sum;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int idx = 0; idx < n; idx++) {
        cin >> cards[idx];
    }
    int answer = findTheClosestNum();
    cout << answer << "\n";
    return 0;
}