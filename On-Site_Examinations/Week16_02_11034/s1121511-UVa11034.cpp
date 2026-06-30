#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {

    int T;
    cin >> T;

    while (T--) {

        int L, M;
        cin >> L >> M;

        L *= 100; // 換算成公分

        queue<int> leftQueue;
        queue<int> rightQueue;

        // 讀入所有車輛
        for (int i = 0; i < M; i++) {

            int len;
            string side;

            cin >> len >> side;

            if (side == "left")
                leftQueue.push(len);
            else
                rightQueue.push(len);
        }

        bool onLeft = true; // 一開始在左岸
        int trip = 0;

        // 模擬渡輪
        while (!leftQueue.empty() || !rightQueue.empty()) {

            int remain = L;

            if (onLeft) {

                // 載左岸車輛
                while (!leftQueue.empty() &&
                       leftQueue.front() <= remain) {

                    remain -= leftQueue.front();
                    leftQueue.pop();
                }
            }
            else {

                // 載右岸車輛
                while (!rightQueue.empty() &&
                       rightQueue.front() <= remain) {

                    remain -= rightQueue.front();
                    rightQueue.pop();
                }
            }

            // 開往另一岸
            onLeft = !onLeft;
            trip++;
        }

        cout << trip << endl;
    }

    return 0;
}
