#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    string strWithSpace;
    getline(cin, strWithSpace);
    int cntWord = 0;
    for (int letter = 1; letter < strWithSpace.length() - 1; letter++) {
        if (strWithSpace[letter] == ' ') {
            cntWord++;
        }
    }
    //입력으로 " "가 들어올수도 있음.
    cntWord = strWithSpace == " " ? cntWord : cntWord + 1;
    cout << cntWord << "\n";
    return 0;
}