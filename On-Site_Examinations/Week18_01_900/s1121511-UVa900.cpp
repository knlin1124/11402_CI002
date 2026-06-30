#include <iostream>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {

    long long dp[51];

    // DP 初始值
    dp[1] = 1;
    dp[2] = 2;

    // 預先計算所有答案
    for (int i = 3; i <= 50; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int n;

    // 持續讀入直到 0
    while (cin >> n && n != 0) {
        cout << dp[n] << endl;
    }

    return 0;
}
