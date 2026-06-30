#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {

    int n, d, r;

    // 持續讀入直到 0 0 0
    while (cin >> n >> d >> r && !(n == 0 && d == 0 && r == 0)) {

        vector<int> morning(n);
        vector<int> evening(n);

        // 讀入早班路線
        for (int i = 0; i < n; i++) {
            cin >> morning[i];
        }

        // 讀入晚班路線
        for (int i = 0; i < n; i++) {
            cin >> evening[i];
        }

        // Morning 升序
        sort(morning.begin(), morning.end());

        // Evening 降序
        sort(evening.begin(), evening.end(), greater<int>());

        int totalCost = 0;

        // 配對並計算加班費
        for (int i = 0; i < n; i++) {

            int work = morning[i] + evening[i];

            if (work > d) {
                totalCost += (work - d) * r;
            }
        }

        cout << totalCost << endl;
    }

    return 0;
}
