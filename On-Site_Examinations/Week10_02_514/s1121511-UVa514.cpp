#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int N;

    // 題目輸入直到 N = 0
    while (cin >> N && N != 0) {

        while (true) {

            vector<int> target(N);

            cin >> target[0];

            // 第一個數字是 0，代表這組測資結束
            if (target[0] == 0)
                break;

            // 讀入剩下目標排列
            for (int i = 1; i < N; i++) {
                cin >> target[i];
            }

            stack<int> st;
            int nextTrain = 1;
            int index = 0;

            // 模擬火車進站
            while (nextTrain <= N) {

                st.push(nextTrain);
                nextTrain++;

                // Stack 頂端符合目前需求，就出站
                while (!st.empty() && st.top() == target[index]) {
                    st.pop();
                    index++;
                }
            }

            // 若 Stack 為空，表示成功排列
            if (st.empty()) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }

        // 每組測資後輸出空白行
        cout << endl;
    }

    return 0;
}
