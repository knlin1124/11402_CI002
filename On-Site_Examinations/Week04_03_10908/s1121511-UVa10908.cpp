#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Reference: ChatGPT 協助整理解法與註解，本人理解後完成。

int main() {
    int T;
    cin >> T;   // 測試資料筆數

    while (T--) {
        int M, N, Q;
        cin >> M >> N >> Q;   // M: 列數, N: 行數, Q: 查詢數量

        vector<string> grid(M);

        // 讀入字元矩陣
        for (int i = 0; i < M; i++) {
            cin >> grid[i];
        }

        // UVa 題目要求每組測資先輸出 M N Q
        cout << M << " " << N << " " << Q << endl;

        while (Q--) {
            int r, c;
            cin >> r >> c;   // 查詢中心點座標，題目座標是 0-based

            char target = grid[r][c]; // 中心點的字元
            int answer = 1;           // 最小一定是 1x1
            int radius = 1;           // 從半徑 1 開始檢查，也就是 3x3

            while (true) {
                int top = r - radius;
                int bottom = r + radius;
                int left = c - radius;
                int right = c + radius;

                // 如果超出矩陣邊界，就不能再擴張
                if (top < 0 || bottom >= M || left < 0 || right >= N) {
                    break;
                }

                bool ok = true;

                // 檢查目前正方形範圍內的所有字元是否都相同
                for (int i = top; i <= bottom && ok; i++) {
                    for (int j = left; j <= right; j++) {
                        if (grid[i][j] != target) {
                            ok = false;
                            break;
                        }
                    }
                }

                // 如果這一層有不同字元，就停止擴張
                if (!ok) {
                    break;
                }

                // 若成功擴張，邊長為 2 * radius + 1
                answer = 2 * radius + 1;
                radius++;
            }

            cout << answer << endl;
        }
    }

    return 0;
}
