#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int T;
    cin >> T;   // 測試資料筆數

    while (T--) {
        int M, N;
        cin >> M >> N;   // M: ADD 數量, N: GET 數量

        vector<int> add(M);
        vector<int> get(N);

        // 讀入 ADD 序列
        for (int i = 0; i < M; i++) {
            cin >> add[i];
        }

        // 讀入 GET 序列
        for (int i = 0; i < N; i++) {
            cin >> get[i];
        }

        multiset<int> box;          // 儲存目前已加入的數字
        multiset<int>::iterator it; // 指向目前要輸出的第 k 小數字

        int addIndex = 0; // 目前已加入到 ADD 序列的位置

        for (int query = 0; query < N; query++) {

            // 持續加入數字，直到加入數量達到 get[query]
            while (addIndex < get[query]) {
                int x = add[addIndex];

                // 如果 box 還是空的，先插入第一個元素
                if (box.empty()) {
                    box.insert(x);
                    it = box.begin();
                }
                else {
                    // 插入前判斷新數字是否會影響目前 iterator 位置
                    box.insert(x);

                    if (x < *it) {
                        it--;
                    }
                }

                addIndex++;
            }

            // 輸出目前第 k 小的數字
            cout << *it << endl;

            // 下一次 GET 要輸出第 k+1 小，所以 iterator 往後移
            it++;
        }

        // 多組測資之間要空一行
        if (T) {
            cout << endl;
        }
    }

    return 0;
}
