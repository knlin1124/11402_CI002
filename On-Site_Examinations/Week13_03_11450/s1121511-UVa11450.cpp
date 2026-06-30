#include <iostream>
#include <vector>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int T;
    cin >> T;   // 測試資料筆數

    while (T--) {
        int M, C;
        cin >> M >> C;   // M: 預算, C: 衣服類別數

        vector<vector<int>> clothes(C);

        // 讀入每一類衣服的價格
        for (int i = 0; i < C; i++) {
            int k;
            cin >> k;   // 這一類有 k 種價格

            clothes[i].resize(k);

            for (int j = 0; j < k; j++) {
                cin >> clothes[i][j];
            }
        }

        vector<vector<bool>> dp(C + 1, vector<bool>(M + 1, false));

        // 一開始還沒買任何衣服，花費 0 是可行的
        dp[0][0] = true;

        // 逐類處理衣服
        for (int i = 0; i < C; i++) {
            for (int spent = 0; spent <= M; spent++) {

                // 如果前 i 類可以花 spent 元
                if (dp[i][spent]) {

                    // 嘗試買第 i 類中的每一種價格
                    for (int price : clothes[i]) {

                        if (spent + price <= M) {
                            dp[i + 1][spent + price] = true;
                        }
                    }
                }
            }
        }

        int answer = -1;

        // 從預算 M 往下找最大可行花費
        for (int money = M; money >= 0; money--) {
            if (dp[C][money]) {
                answer = money;
                break;
            }
        }

        if (answer == -1)
            cout << "no solution" << endl;
        else
            cout << answer << endl;
    }

    return 0;
}
