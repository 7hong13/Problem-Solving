/*
    number는 1 이상 10000 이하의 자연수이므로, 
    10000번째 인덱스를 활용하기 위해선 배열 크기가 최소 10001 이어야 한다.
    index가 0부터 시작한다고 착각하고 배열 크기를 잘못 할당하는 실수를 조심해야 한다.
*/

#include <iostream>
using namespace std;
int arrMarkingIndex[10001] = { 0, };
int n;
void sortAscendingOrder() {
    for (int idx = 0; idx < n; idx++) {
        int number;
        cin >> number;
        arrMarkingIndex[number]++;
    }
    for (int idx = 1; idx <= 10000; idx++) {
        if (arrMarkingIndex[idx] == 0) continue;
        for (int value = 0; value < arrMarkingIndex[idx]; value++) {
            cout << idx << "\n";
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    sortAscendingOrder();
    return 0;
}