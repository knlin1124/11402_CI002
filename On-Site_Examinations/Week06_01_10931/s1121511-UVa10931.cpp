#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int n;

    // 持續讀入數字，直到輸入 0 為止
    while (cin >> n && n != 0) {
        string binary = "";
        int countOne = 0;   // 計算二進位中 1 的數量
        int temp = n;       // 保留 n，用 temp 來轉換

        // 十進位轉二進位
        while (temp > 0) {
            int bit = temp % 2;   // 取得最低位元

            if (bit == 1) {
                countOne++;
            }

            binary += char(bit + '0'); // 將 0 或 1 加入字串
            temp /= 2;
        }

        // 因為轉換時是從低位元開始，所以要反轉
        reverse(binary.begin(), binary.end());

        cout << "The parity of " << binary
             << " is " << countOne << " (mod 2)." << endl;
    }

    return 0;
}
