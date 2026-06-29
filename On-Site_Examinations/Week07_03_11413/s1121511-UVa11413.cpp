#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

// 判斷容量 capacity 是否能在 m 個 container 內裝完
bool canFill(const vector<int>& vessels, int m, int capacity) {
    int used = 1;       // 至少會使用一個 container
    int current = 0;    // 目前 container 已使用容量

    for (int v : vessels) {
        // 如果單一 vessel 已經比 capacity 大，代表不可能
        if (v > capacity) {
            return false;
        }

        // 如果目前 container 還放得下，就放進去
        if (current + v <= capacity) {
            current += v;
        }
        // 放不下就換下一個 container
        else {
            used++;
            current = v;
        }
    }

    // 使用的 container 數量不超過 m 就可行
    return used <= m;
}

int main() {
    int n, m;

    // 多組測資，讀到 EOF 結束
    while (cin >> n >> m) {
        vector<int> vessels(n);

        int left = 0;   // 最小可能容量
        int right = 0;  // 最大可能容量

        for (int i = 0; i < n; i++) {
            cin >> vessels[i];
            left = max(left, vessels[i]); // 至少要能裝最大 vessel
            right += vessels[i];          // 最多就是全部裝同一個 container
        }

        int answer = right;

        // Binary Search 找最小可行容量
        while (left <= right) {
            int mid = (left + right) / 2;

            if (canFill(vessels, m, mid)) {
                answer = mid;      // mid 可行，嘗試更小
                right = mid - 1;
            }
            else {
                left = mid + 1;    // mid 太小，需要更大容量
            }
        }

        cout << answer << endl;
    }

    return 0;
}
