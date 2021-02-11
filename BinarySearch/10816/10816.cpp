#include <iostream>
#include <algorithm>
#define MAX 500000
using namespace std;
int N, M;
int cards[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}
void findNumOfCards() {
    cin >> M;
    sort(cards, cards + N);
    while (M--) {
        int num;
        cin >> num;
        if (!binary_search(cards, cards + N, num)) cout << "0 ";
        else {
            auto currIter = lower_bound(cards, cards + N, num);
            auto nextIter = upper_bound(cards, cards + N, num);
            cout << nextIter - currIter << ' ';
        }
    }
}

int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        cin >> cards[idx];
    }
    findNumOfCards();
    return 0;
}