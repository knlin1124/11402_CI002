#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    vector<int> numbers;
    int x;

    // 持續讀入數字直到 EOF
    while (cin >> x) {
        numbers.push_back(x);  // 將新數字加入陣列

        // 每次加入後重新排序，方便取得中位數
        sort(numbers.begin(), numbers.end());

        int n = numbers.size();

        // 如果目前數量是奇數，中位數就是中間那個
        if (n % 2 == 1) {
            cout << numbers[n / 2] << endl;
        }
        // 如果目前數量是偶數，中位數是中間兩個數的平均
        else {
            cout << (numbers[n / 2 - 1] + numbers[n / 2]) / 2 << endl;
        }
    }

    return 0;
}
