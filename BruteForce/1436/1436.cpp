#include <iostream>
#include <string>
using namespace std;
int N;
void init() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void printTitle() {
    int titleN = 0;
    for (int num = 666; ; num++) {
        string title = to_string(num);
        for (int idx = 0; idx < title.size() - 2; idx++) {
            if (title[idx] == '6' && 
                title[idx] == title[idx + 1] && title[idx + 1] == title[idx + 2]) {
                    titleN++;
                    break;
                }
        }
        if (titleN == N) {
            cout << title << "\n";
            break;
        }
    }
}

int main() {
    init();
    cin >> N;
    printTitle();
    return 0;
}