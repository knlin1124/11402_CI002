#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

struct Segment {
    int left, right;

    bool operator<(const Segment& other) const {
        if (left != other.left)
            return left < other.left;
        return right > other.right;
    }
};

int main() {

    int T;
    cin >> T;

    while (T--) {

        int M;
        cin >> M;

        vector<Segment> segs;

        // 讀入所有線段，直到 0 0
        while (true) {
            int l, r;
            cin >> l >> r;

            if (l == 0 && r == 0)
                break;

            segs.push_back({l, r});
        }

        // 排序
        sort(segs.begin(), segs.end());

        vector<Segment> answer;

        int current = 0;
        int i = 0;
        int n = segs.size();

        bool success = true;

        while (current < M) {

            int farthest = current;
            Segment best;

            // 找所有可以接上的線段
            while (i < n && segs[i].left <= current) {

                if (segs[i].right > farthest) {
                    farthest = segs[i].right;
                    best = segs[i];
                }

                i++;
            }

            // 無法繼續覆蓋
            if (farthest == current) {
                success = false;
                break;
            }

            answer.push_back(best);
            current = farthest;
        }

        if (!success) {
            cout << 0 << endl;
        }
        else {

            cout << answer.size() << endl;

            for (auto s : answer) {
                cout << s.left << " " << s.right << endl;
            }
        }

        if (T)
            cout << endl;
    }

    return 0;
}
