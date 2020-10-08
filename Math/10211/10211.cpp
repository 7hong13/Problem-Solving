#include <iostream>
using namespace std;
int arr[1001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int max = -1001, sum = 0;
        for (int idx = 0; idx < n; idx++) {
            int x;
            cin >> x;
            arr[idx] = x;
        }
        for (int idx = 0; idx < n; idx++){
            sum = 0;
            for (int start = idx; start < n; start++) {
                sum += arr[start];
                if (max < sum) max = sum;
            }
        }
        cout << max << "\n";
    }
    return 0;
}