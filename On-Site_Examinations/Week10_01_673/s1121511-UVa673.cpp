#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int T;
    cin >> T;
    cin.ignore(); // 清除換行

    while (T--) {
        string s;
        getline(cin, s);

        stack<char> st;
        bool ok = true;

        // 逐字元檢查括號
        for (char ch : s) {

            // 左括號直接放入 Stack
            if (ch == '(' || ch == '[') {
                st.push(ch);
            }
            // 遇到右括號
            else {

                // Stack 已空，代表沒有對應左括號
                if (st.empty()) {
                    ok = false;
                    break;
                }

                // 檢查是否成功配對
                if (ch == ')' && st.top() == '(') {
                    st.pop();
                }
                else if (ch == ']' && st.top() == '[') {
                    st.pop();
                }
                else {
                    ok = false;
                    break;
                }
            }
        }

        // 若 Stack 還有剩，表示配對未完成
        if (!st.empty()) {
            ok = false;
        }

        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
