#include <iostream>
#include <cstring>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

long long dp[65][65];

// 計算 trib(n, back) 的呼叫次數
long long trib(int n, int back) {

    // 基本情況：n <= 1 時，只算目前這次呼叫
    if (n <= 1) {
        return 1;
    }

    // 如果已經算過，直接回傳
    if (dp[n][back] != -1) {
        return dp[n][back];
    }

    long long result = 1; // 計算目前這次呼叫本身

    // 呼叫 trib(n-1), trib(n-2), ..., trib(n-back)
    for (int i = 1; i <= back; i++) {
        result += trib(n - i, back);
    }

    dp[n][back] = result;
    return result;
}

int main() {
    int n, back;
    int caseNumber = 1;

    // 題目規定 n > 60 時結束
    while (cin >> n >> back && n <= 60) {

        memset(dp, -1, sizeof(dp));

        cout << "Case " << caseNumber++ << ": "
             << trib(n, back) << endl;
    }

    return 0;
}
