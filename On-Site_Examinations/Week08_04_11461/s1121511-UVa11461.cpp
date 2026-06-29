#include <iostream>
#include <cmath>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int A, B;

    // 持續讀入直到 A 和 B 都為 0
    while (cin >> A >> B && !(A == 0 && B == 0)) {

        // 第一個可能的平方根
        int first = ceil(sqrt(A));

        // 最後一個可能的平方根
        int last = floor(sqrt(B));

        // 若沒有完全平方數
        if (last < first) {
            cout << 0 << endl;
        }
        else {
            // 計算完全平方數的個數
            cout << last - first + 1 << endl;
        }
    }

    return 0;
}
