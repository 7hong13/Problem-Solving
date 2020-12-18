#include <iostream>
#include <cstring>
using namespace std;
struct numInfo{
    string num;
    int strike;
    int ball;
};
numInfo numbers[100];
int ans = 0, N;
void init() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void findPossibleAns() {
    for (int num = 111; num <= 999; num++) {
        char x, y, z;
        x = num / 100 + 48;
        y = (num % 100) / 10 + 48;
        z = (num % 10) + 48;
        if (x == '0' || y == '0' || z == '0') continue;
        if (x == y || y == z || x == z) continue;
        int cnt = 0;
        int b, s;
        for (int idx = 0; idx < N; idx++) {
            b = s = 0;
            if (numbers[idx].num[0] == x) s++;
            if (numbers[idx].num[1] == y) s++;
            if (numbers[idx].num[2] == z) s++;
            if (numbers[idx].num[0] == y) b++;
            if (numbers[idx].num[0] == z) b++;
            if (numbers[idx].num[1] == x) b++;
            if (numbers[idx].num[1] == z) b++;
            if (numbers[idx].num[2] == x) b++;
            if (numbers[idx].num[2] == y) b++;
            if (numbers[idx].ball == b && numbers[idx].strike == s) cnt++;
        }
        if (cnt == N) ans++;
    } 
}

int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        string num;
        int s, b;
        cin >> num >> s >> b;
        numbers[idx].num = num;
        numbers[idx].strike = s;
        numbers[idx].ball = b;
    }
    findPossibleAns();
    cout << ans << "\n";
    return 0;
}