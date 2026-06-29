#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int T;
    cin >> T;   // 測試資料筆數

    while (T--) {
        int n;
        cin >> n;   // 火車車廂數量

        vector<int> train(n);

        // 讀入火車車廂順序
        for (int i = 0; i < n; i++) {
            cin >> train[i];
        }

        int swaps = 0;   // 紀錄交換次數

        // 使用 Bubble Sort 模擬相鄰交換
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {

                // 若前面的車廂編號較大，就交換
                if (train[j] > train[j + 1]) {
                    swap(train[j], train[j + 1]);
                    swaps++;
                }
            }
        }

        // 題目指定輸出格式
        cout << "Optimal train swapping takes "
             << swaps << " swaps." << endl;
    }

    return 0;
}
