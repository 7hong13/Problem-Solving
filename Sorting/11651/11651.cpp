#include <iostream>
#include <algorithm>
using namespace std;
struct Coordinate {
    int x;
    int y;
};
bool compare(Coordinate dot1, Coordinate dot2) {
    if (dot1.y == dot2.y) return dot1.x < dot2.x;
    return dot1.y < dot2.y;
}
Coordinate arrForSorting[100001];

int main() {
    int n;
    cin >> n;
    for (int idx = 0; idx < n; idx++) {
        cin >> arrForSorting[idx].x >> arrForSorting[idx].y;
    }
    sort(arrForSorting, arrForSorting + n, compare);
     for (int idx = 0; idx < n; idx++) {
        cout << arrForSorting[idx].x << " " << arrForSorting[idx].y <<"\n";
    }
    return 0;
}