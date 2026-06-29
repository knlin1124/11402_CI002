#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int N, Q;
    int caseNumber = 1;

    // N = 彈珠數量, Q = 查詢數量
    // 當 N 和 Q 都是 0 時結束
    while (cin >> N >> Q && (N != 0 || Q != 0)) {
        vector<int> marbles(N);

        // 讀入所有彈珠
        for (int i = 0; i < N; i++) {
            cin >> marbles[i];
        }

        // 題目要求查詢排序後的位置
        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << caseNumber << ":" << endl;

        while (Q--) {
            int query;
            cin >> query;

            // lower_bound 找到第一個 >= query 的位置
            auto it = lower_bound(marbles.begin(), marbles.end(), query);

            // 如果找到且值等於 query，代表存在
            if (it != marbles.end() && *it == query) {
                int position = it - marbles.begin() + 1; // 轉成 1-based
                cout << query << " found at " << position << endl;
            }
            else {
                cout << query << " not found" << endl;
            }
        }

        caseNumber++;
    }

    return 0;
}
