#include <iostream>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int n;

    // 持續讀入，直到輸入 0
    while (cin >> n && n != 0) {

        // 如果還不是一位數，就持續計算數位和
        while (n >= 10) {

            int sum = 0;

            // 將每一位數字加總
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }

            // 更新 n，繼續判斷是否需要再次相加
            n = sum;
        }

        // 輸出最後的一位數
        cout << n << endl;
    }

    return 0;
}
