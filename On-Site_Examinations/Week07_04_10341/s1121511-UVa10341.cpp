#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int p, q, r, s, t, u;

// 計算題目給的函數值
double f(double x) {
    return p * exp(-x)
         + q * sin(x)
         + r * cos(x)
         + s * tan(x)
         + t * x * x
         + u;
}

int main() {
    // 輸入直到 EOF
    while (cin >> p >> q >> r >> s >> t >> u) {
        double left = 0.0;
        double right = 1.0;

        // 如果 f(0) 和 f(1) 同號，代表沒有解
        if (f(left) * f(right) > 0) {
            cout << "No solution" << endl;
            continue;
        }

        // Binary Search 找 x
        for (int i = 0; i < 100; i++) {
            double mid = (left + right) / 2.0;

            // 因為這題函數在 [0,1] 內是單調遞減
            // 若 f(mid) > 0，代表答案在右邊
            if (f(mid) > 0) {
                left = mid;
            }
            // 若 f(mid) <= 0，代表答案在左邊或就是答案
            else {
                right = mid;
            }
        }

        cout << fixed << setprecision(4) << (left + right) / 2.0 << endl;
    }

    return 0;
}
