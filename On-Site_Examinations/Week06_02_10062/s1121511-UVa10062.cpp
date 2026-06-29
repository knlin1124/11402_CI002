#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    string line;
    bool firstCase = true;

    // 每讀到一行就是一組測資
    while (getline(cin, line)) {

        // 不同測資之間需空一行
        if (!firstCase)
            cout << endl;
        firstCase = false;

        int freq[128] = {0};

        // 統計每個 ASCII 字元出現次數
        for (char ch : line) {
            freq[(int)ch]++;
        }

        vector<pair<int, int>> result;

        // 將出現過的字元存入 vector
        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0) {
                result.push_back({i, freq[i]});
            }
        }

        // 排序：
        // 1. 次數由小到大
        // 2. ASCII 值由大到小
        sort(result.begin(), result.end(),
             [](pair<int, int> a, pair<int, int> b) {
                 if (a.second != b.second)
                     return a.second < b.second;
                 return a.first > b.first;
             });

        // 輸出 ASCII 值與出現次數
        for (auto item : result) {
            cout << item.first << " " << item.second << endl;
        }
    }

    return 0;
}
