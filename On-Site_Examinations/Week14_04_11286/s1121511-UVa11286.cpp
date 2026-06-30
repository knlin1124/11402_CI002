#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {

    int n;

    // 持續讀入直到 n = 0
    while (cin >> n && n != 0) {

        map<vector<int>, int> cnt;

        // 讀入每位學生
        for (int i = 0; i < n; i++) {

            vector<int> course(5);

            for (int j = 0; j < 5; j++) {
                cin >> course[j];
            }

            // 課程順序不重要，因此先排序
            sort(course.begin(), course.end());

            cnt[course]++;
        }

        int maxFreq = 0;

        // 找出最高出現次數
        for (auto item : cnt) {
            maxFreq = max(maxFreq, item.second);
        }

        int answer = 0;

        // 將所有並列最高的人數加總
        for (auto item : cnt) {
            if (item.second == maxFreq) {
                answer += item.second;
            }
        }

        cout << answer << endl;
    }

    return 0;
}
