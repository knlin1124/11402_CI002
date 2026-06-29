#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int kadane(vector<int>& arr) {
    int best = arr[0];
    int current = arr[0];

    // 一維最大連續子陣列
    for (int i = 1; i < arr.size(); i++) {
        current = max(arr[i], current + arr[i]);
        best = max(best, current);
    }

    return best;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));

    // 讀入矩陣
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    int answer = -1000000000;

    // 固定上邊界
    for (int top = 0; top < N; top++) {
        vector<int> temp(N, 0);

        // 固定下邊界
        for (int bottom = top; bottom < N; bottom++) {

            // 將 top 到 bottom 之間每一欄加總
            for (int col = 0; col < N; col++) {
                temp[col] += matrix[bottom][col];
            }

            // 對壓縮後的一維陣列找最大連續子陣列
            answer = max(answer, kadane(temp));
        }
    }

    cout << answer << endl;

    return 0;
}
