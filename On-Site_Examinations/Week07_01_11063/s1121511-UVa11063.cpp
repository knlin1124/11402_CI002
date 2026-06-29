#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int n;
    int caseNumber = 1;

    // 題目輸入直到 EOF
    while (cin >> n) {
        vector<int> a(n);
        bool isB2 = true;

        // 讀入數列
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // 檢查是否為正整數以及是否嚴格遞增
        for (int i = 0; i < n; i++) {
            if (a[i] <= 0) {
                isB2 = false;
            }

            if (i > 0 && a[i] <= a[i - 1]) {
                isB2 = false;
            }
        }

        set<int> sums;

        // 檢查所有 i <= j 的兩兩相加結果是否重複
        for (int i = 0; i < n && isB2; i++) {
            for (int j = i; j < n; j++) {
                int sum = a[i] + a[j];

                // 如果這個和已經出現過，代表不是 B2-Sequence
                if (sums.count(sum)) {
                    isB2 = false;
                    break;
                }

                sums.insert(sum);
            }
        }

        cout << "Case #" << caseNumber << ": ";

        if (isB2) {
            cout << "It is a B2-Sequence." << endl << endl;
        }
        else {
            cout << "It is not a B2-Sequence." << endl << endl;
        }

        caseNumber++;
    }

    return 0;
}
