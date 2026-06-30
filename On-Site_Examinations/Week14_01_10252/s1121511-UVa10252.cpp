#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    string A, B;

    // 持續讀入直到 EOF
    while (getline(cin, A) && getline(cin, B)) {

        vector<int> cntA(26, 0);
        vector<int> cntB(26, 0);

        // 統計第一個字串
        for (char ch : A) {
            cntA[ch - 'a']++;
        }

        // 統計第二個字串
        for (char ch : B) {
            cntB[ch - 'a']++;
        }

        // 依照字母順序輸出共同字元
        for (int i = 0; i < 26; i++) {

            int times = min(cntA[i], cntB[i]);

            while (times--) {
                cout << char(i + 'a');
            }
        }

        cout << endl;
    }

    return 0;
}
