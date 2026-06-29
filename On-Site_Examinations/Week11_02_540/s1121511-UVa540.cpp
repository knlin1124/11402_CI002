#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int T;
    int scenario = 1;

    // 持續讀入直到 T = 0
    while (cin >> T && T != 0) {

        cout << "Scenario #" << scenario++ << endl;

        map<int, int> teamID;

        // 建立 member -> team 對照表
        for (int i = 0; i < T; i++) {
            int n;
            cin >> n;

            while (n--) {
                int member;
                cin >> member;
                teamID[member] = i;
            }
        }

        // 每個 Team 一個 Queue
        queue<int> teamQueue[1000];

        // Team 的 Queue
        queue<int> order;

        string cmd;

        while (cin >> cmd && cmd != "STOP") {

            if (cmd == "ENQUEUE") {

                int member;
                cin >> member;

                int team = teamID[member];

                // 如果 Team 目前沒有排隊，加入 Team Queue
                if (teamQueue[team].empty()) {
                    order.push(team);
                }

                teamQueue[team].push(member);
            }

            else if (cmd == "DEQUEUE") {

                int team = order.front();

                cout << teamQueue[team].front() << endl;

                teamQueue[team].pop();

                // 若 Team 已沒人，就移除 Team
                if (teamQueue[team].empty()) {
                    order.pop();
                }
            }
        }

        cout << endl;
    }

    return 0;
}
