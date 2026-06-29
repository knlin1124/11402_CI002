#include <iostream>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int N, B, H, W;

    // 題目輸入直到 EOF
    while (cin >> N >> B >> H >> W) {

        int answer = 1e9; // 紀錄最小花費

        // 逐間飯店檢查
        for (int i = 0; i < H; i++) {

            int price;
            cin >> price; // 每人住宿價格

            // 檢查每一週
            for (int j = 0; j < W; j++) {

                int beds;
                cin >> beds;

                // 若床位足夠
                if (beds >= N) {

                    int totalCost = price * N;

                    // 若符合預算，就更新最便宜方案
                    if (totalCost <= B) {
                        answer = min(answer, totalCost);
                    }
                }
            }
        }

        // 若沒有找到符合條件的方案
        if (answer == 1e9) {
            cout << "stay home" << endl;
        }
        else {
            cout << answer << endl;
        }
    }

    return 0;
}
