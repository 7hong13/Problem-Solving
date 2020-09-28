#include <iostream>
#include <algorithm>
using namespace std;
int arrForSorting[1000001];

int main() {
    cin.tie(nullptr);
	ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int idx = 0; idx < n; idx++) {
        cin >> arrForSorting[idx];
    }
    sort(arrForSorting, arrForSorting + n);
    for (int idx = 0; idx < n; idx++) {
        cout << arrForSorting[idx] << "\n";
    }
    return 0;
}