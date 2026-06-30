#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {

    int C, S;
    int setNumber = 1;

    while (cin >> C >> S) {

        vector<int> sample(2 * C, 0);
        double sum = 0;

        // 讀入樣本重量
        for (int i = 0; i < S; i++) {
            cin >> sample[i];
            sum += sample[i];
        }

        // 排序
        sort(sample.begin(), sample.end());

        double average = sum / C;
        double imbalance = 0;

        cout << "Set #" << setNumber++ << endl;

        for (int i = 0; i < C; i++) {

            int left = sample[i];
            int right = sample[2 * C - 1 - i];

            cout << " " << i << ":";

            int chamberWeight = 0;

            if (left != 0) {
                cout << " " << left;
                chamberWeight += left;
            }

            if (right != 0) {
                cout << " " << right;
                chamberWeight += right;
            }

            cout << endl;

            imbalance += fabs(chamberWeight - average);
        }

        cout << "IMBALANCE = ";
        cout << fixed << setprecision(5) << imbalance << endl;
        cout << endl;
    }

    return 0;
}
