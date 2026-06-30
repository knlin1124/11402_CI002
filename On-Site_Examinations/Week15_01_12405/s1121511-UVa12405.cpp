#include <iostream>
#include <string>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        int n;
        cin >> n;

        string field;
        cin >> field;

        int answer = 0;

        // 從左到右掃描
        for (int i = 0; i < n; ) {

            if (field[i] == '#') {
                i++;    // 障礙物直接跳過
            }
            else {
                // 放置一個稻草人
                answer++;

                // 稻草人可覆蓋 i、i+1、i+2
                i += 3;
            }
        }

        cout << "Case " << tc << ": " << answer << endl;
    }

    return 0;
}
