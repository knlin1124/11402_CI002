#include <iostream>
#include <string>
#include <climits>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {

    int bin[3][3];

    // 六種排列
    string order[6] = {
        "BCG",
        "BGC",
        "CBG",
        "CGB",
        "GBC",
        "GCB"
    };

    // 持續讀入直到 EOF
    while (cin >>
        bin[0][0] >> bin[0][1] >> bin[0][2] >>
        bin[1][0] >> bin[1][1] >> bin[1][2] >>
        bin[2][0] >> bin[2][1] >> bin[2][2]) {

        int total = 0;

        // 計算所有瓶子總數
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                total += bin[i][j];

        int bestMove = INT_MAX;
        string bestOrder;

        // 六種排列全部測試
        for (int k = 0; k < 6; k++) {

            int keep = 0;

            for (int i = 0; i < 3; i++) {

                int color;

                if (order[k][i] == 'B') color = 0;
                else if (order[k][i] == 'G') color = 1;
                else color = 2;

                // 保留下來不用搬的瓶子
                keep += bin[i][color];
            }

            int move = total - keep;

            // 更新最佳答案
            if (move < bestMove ||
                (move == bestMove && order[k] < bestOrder)) {

                bestMove = move;
                bestOrder = order[k];
            }
        }

        cout << bestOrder << " " << bestMove << endl;
    }

    return 0;
}
