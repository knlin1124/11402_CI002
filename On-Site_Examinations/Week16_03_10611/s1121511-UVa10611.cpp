#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);

    // 讀入母猩猩身高，題目已保證排序
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int q;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;

        // lower_bound 找第一個 >= x 的位置
        auto low = lower_bound(heights.begin(), heights.end(), x);

        // upper_bound 找第一個 > x 的位置
        auto high = upper_bound(heights.begin(), heights.end(), x);

        // 比 x 小的最大值
        if (low == heights.begin()) {
            cout << "X ";
        }
        else {
            cout << *(low - 1) << " ";
        }

        // 比 x 大的最小值
        if (high == heights.end()) {
            cout << "X" << endl;
        }
        else {
            cout << *high << endl;
        }
    }

    return 0;
}
