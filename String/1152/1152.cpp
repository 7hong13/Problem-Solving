#include <iostream>
#include <string>
using namespace std;
int countWords(string strWithSpace) {
    int wordCount;
    for (int letter = 1; letter < strWithSpace.length() - 1; letter++) {
        char space = ' ';
        if (strWithSpace[letter] == space) {
            wordCount++;
        }
    }
    //입력으로 " "가 들어올수도 있음.
    wordCount = strWithSpace == " " ? wordCount : wordCount + 1;
    return wordCount;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    string strWithSpace;
    getline(cin, strWithSpace);
    int wordCount = countWords(strWithSpace);
    cout << wordCount << "\n";
    return 0;
}