#include <iostream>
#include <map>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {

    int T;
    cin >> T;

    while (T--) {

        int n, m;
        cin >> n >> m;

        map<int, int> cnt;

        // 統計第一個串列
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }

        int answer = 0;

        // 處理第二個串列
        for (int i = 0; i < m; i++) {

            int x;
            cin >> x;

            if (cnt[x] > 0) {
                // 抵消一個相同數字
                cnt[x]--;
            }
            else {
                // 第二個串列多出一個數字
                answer++;
            }
        }

        // 第一個串列剩餘的數字也要刪除
        for (auto item : cnt) {
            answer += item.second;
        }

        cout << answer << endl;
    }

    return 0;
}
