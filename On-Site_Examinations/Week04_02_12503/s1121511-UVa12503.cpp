#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Reference: ChatGPT 協助整理解法與註解，本人理解後完成。

int main() {
    int T;
    cin >> T;   // 測試資料筆數

    while (T--) {
        int n;
        cin >> n;   // 本次共有 n 個指令

        vector<int> move(n + 1); // 紀錄每一步實際移動方向
        int position = 0;         // 機器人目前位置

        for (int i = 1; i <= n; i++) {
            string cmd;
            cin >> cmd;

            // LEFT：往左走一步
            if (cmd == "LEFT") {
                move[i] = -1;
            }
            // RIGHT：往右走一步
            else if (cmd == "RIGHT") {
                move[i] = 1;
            }
            // SAME AS x：執行第 x 步相同的動作
            else {
                string temp;
                int index;

                cin >> temp >> index;   // 讀掉 "AS" 和指令編號

                move[i] = move[index];
            }

            // 更新目前位置
            position += move[i];
        }

        // 輸出最後位置
        cout << position << endl;
    }

    return 0;
}
