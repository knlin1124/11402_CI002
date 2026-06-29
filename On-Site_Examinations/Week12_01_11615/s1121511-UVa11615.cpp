#include <iostream>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    long long a, b;

    // 題目輸入直到 EOF
    while (cin >> a >> b) {

        // 不斷往上找父節點，直到兩者相同
        while (a != b) {

            // 較大的節點通常位於較深的位置，先往上移
            if (a > b) {
                a /= 2;
            }
            else {
                b /= 2;
            }
        }

        // 最後相同的位置就是共同祖先
        cout << a << endl;
    }

    return 0;
}
