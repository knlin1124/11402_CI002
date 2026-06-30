#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {

    // dp[i]：第 i 個 Fibonacci 數
    cpp_int dp[5001];

    // Fibonacci 初始值
    dp[0] = 0;
    dp[1] = 1;

    // 預先計算到 F(5000)
    for (int i = 2; i <= 5000; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int n;

    // 持續讀入直到 EOF
    while (cin >> n) {
        cout << "The Fibonacci number for " << n
             << " is " << dp[n] << endl;
    }

    return 0;
}
