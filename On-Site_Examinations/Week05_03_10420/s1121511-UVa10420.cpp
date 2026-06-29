#include <iostream>
#include <map>
#include <string>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int n;
    cin >> n;   // 資料筆數

    map<string, int> countryCount; // 自動依照國家名稱排序
    string country, name;

    for (int i = 0; i < n; i++) {
        cin >> country;          // 每行第一個單字是國家名稱
        getline(cin, name);      // 讀掉後面的名字

        countryCount[country]++; // 統計國家出現次數
    }

    // map 會自動依照 country 字母順序輸出
    for (auto item : countryCount) {
        cout << item.first << " " << item.second << endl;
    }

    return 0;
}
