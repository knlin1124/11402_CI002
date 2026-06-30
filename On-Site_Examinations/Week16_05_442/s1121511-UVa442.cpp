#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

struct Matrix {
    int row;
    int col;
};

int main() {

    int n;
    cin >> n;

    map<char, Matrix> matrix;

    // 讀入每個矩陣的大小
    for (int i = 0; i < n; i++) {

        char name;
        cin >> name;

        cin >> matrix[name].row >> matrix[name].col;
    }

    string expr;

    // 讀取所有運算式直到 EOF
    while (cin >> expr) {

        stack<Matrix> st;

        long long answer = 0;
        bool error = false;

        for (char ch : expr) {

            // 遇到矩陣名稱
            if (ch >= 'A' && ch <= 'Z') {

                st.push(matrix[ch]);
            }

            // 遇到 ')' 表示完成一次乘法
            else if (ch == ')') {

                Matrix b = st.top();
                st.pop();

                Matrix a = st.top();
                st.pop();

                // 無法相乘
                if (a.col != b.row) {
                    error = true;
                    break;
                }

                // 計算乘法次數
                answer += 1LL * a.row * a.col * b.col;

                // 新矩陣放回 Stack
                st.push({a.row, b.col});
            }
        }

        if (error)
            cout << "error" << endl;
        else
            cout << answer << endl;
    }

    return 0;
}
