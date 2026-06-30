#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int n, m;
    int fieldNumber = 1;

    // 八個方向
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    // 持續讀入直到 0 0
    while (cin >> n >> m && !(n == 0 && m == 0)) {

        vector<string> field(n);
        vector<vector<int>> cnt(n, vector<int>(m, 0));

        // 讀入地圖
        for (int i = 0; i < n; i++) {
            cin >> field[i];
        }

        // 更新每顆地雷周圍八格
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (field[i][j] == '*') {

                    for (int k = 0; k < 8; k++) {

                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        // 檢查是否超出邊界
                        if (nx >= 0 && nx < n &&
                            ny >= 0 && ny < m &&
                            field[nx][ny] != '*') {

                            cnt[nx][ny]++;
                        }
                    }
                }
            }
        }

        // 每組測資之間要空一行
        if (fieldNumber > 1)
            cout << endl;

        cout << "Field #" << fieldNumber++ << ":" << endl;

        // 輸出答案
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (field[i][j] == '*')
                    cout << '*';
                else
                    cout << cnt[i][j];
            }

            cout << endl;
        }
    }

    return 0;
}
