#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int n;
    cin >> n;          // 要讀取的文字行數
    cin.ignore();      // 清除讀完 n 後留下的換行符號

    vector<int> count(26, 0);

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);   // 讀取整行文字，包含空白

        for (char ch : line) {
            // 只統計英文字母
            if (isalpha(ch)) {
                ch = toupper(ch);       // 統一轉成大寫
                count[ch - 'A']++;      // 對應到 0~25
            }
        }
    }

    vector<pair<char, int>> result;

    // 把有出現過的字母存進 result
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            result.push_back({'A' + i, count[i]});
        }
    }

    // 排序規則：
    // 1. 次數多的在前
    // 2. 次數相同時，字母小的在前
    sort(result.begin(), result.end(), [](pair<char, int> a, pair<char, int> b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    // 輸出結果
    for (auto item : result) {
        cout << item.first << " " << item.second << endl;
    }

    return 0;
}
