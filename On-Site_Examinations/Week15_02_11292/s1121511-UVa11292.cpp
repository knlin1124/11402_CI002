#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {

    int n, m;

    // 持續讀入直到 0 0
    while (cin >> n >> m && !(n == 0 && m == 0)) {

        vector<int> dragon(n);
        vector<int> knight(m);

        // 讀入所有龍頭直徑
        for (int i = 0; i < n; i++) {
            cin >> dragon[i];
        }

        // 讀入所有騎士身高
        for (int i = 0; i < m; i++) {
            cin >> knight[i];
        }

        // 排序
        sort(dragon.begin(), dragon.end());
        sort(knight.begin(), knight.end());

        int i = 0;          // 龍頭指標
        int j = 0;          // 騎士指標
        long long cost = 0; // 總花費

        // Greedy 配對
        while (i < n && j < m) {

            if (knight[j] >= dragon[i]) {

                // 找到可砍龍頭的騎士
                cost += knight[j];

                i++;
                j++;
            }
            else {
                // 騎士太矮，換下一位
                j++;
            }
        }

        // 若所有龍頭都被砍掉
        if (i == n) {
            cout << cost << endl;
        }
        else {
            cout << "Loowater is doomed!" << endl;
        }
    }

    return 0;
}
