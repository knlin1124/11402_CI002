#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int M;

// 判斷是否為奇數
bool isOdd(int x) {
    return x % 2 != 0;
}

// 自訂排序規則
bool cmp(int a, int b) {
    int modA = a % M;
    int modB = b % M;

    // 1. 先比較對 M 取餘數，餘數小的排前面
    if (modA != modB) {
        return modA < modB;
    }

    bool oddA = isOdd(a);
    bool oddB = isOdd(b);

    // 2. 餘數相同時，奇數排在偶數前面
    if (oddA != oddB) {
        return oddA;
    }

    // 3. 如果都是奇數，數字大的排前面
    if (oddA && oddB) {
        return a > b;
    }

    // 4. 如果都是偶數，數字小的排前面
    return a < b;
}

int main() {
    int N;

    while (cin >> N >> M) {
        // 題目要求每組都先輸出 N M
        cout << N << " " << M << endl;

        // 讀到 0 0 代表結束
        if (N == 0 && M == 0) {
            break;
        }

        vector<int> numbers(N);

        // 讀入所有數字
        for (int i = 0; i < N; i++) {
            cin >> numbers[i];
        }

        // 依照題目規則排序
        sort(numbers.begin(), numbers.end(), cmp);

        // 輸出排序後結果
        for (int x : numbers) {
            cout << x << endl;
        }
    }

    return 0;
}
