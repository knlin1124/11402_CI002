#include <iostream>
#include <vector>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

vector<int> answer;

// 計算高度 h 最多可以放多少節點
int maxNodes(int h) {
    if (h >= 31) return 1000000000;
    return (1 << h) - 1;
}

// 建構 BST 的插入順序
void build(int left, int right, int h) {
    if (left > right) return;

    // 選擇 root，使左右子樹都能在剩餘高度中放下
    for (int root = left; root <= right; root++) {

        int leftCount = root - left;
        int rightCount = right - root;

        if (leftCount <= maxNodes(h - 1) &&
            rightCount <= maxNodes(h - 1)) {

            answer.push_back(root);

            build(left, root - 1, h - 1);
            build(root + 1, right, h - 1);

            return;
        }
    }
}

int main() {
    int n, h;
    int caseNumber = 1;

    // 讀到 0 0 結束
    while (cin >> n >> h && !(n == 0 && h == 0)) {

        answer.clear();

        cout << "Case " << caseNumber++ << ": ";

        if (n > maxNodes(h)) {
            cout << "Impossible." << endl;
        }
        else {
            build(1, n, h);

            for (int i = 0; i < answer.size(); i++) {
                if (i) cout << " ";
                cout << answer[i];
            }

            cout << endl;
        }
    }

    return 0;
}
