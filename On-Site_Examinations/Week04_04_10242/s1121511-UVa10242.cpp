#include <iostream>
#include <iomanip>
using namespace std;

// Reference: ChatGPT 協助整理解法與註解，本人理解後完成。

struct Point {
    double x, y;
};

// 判斷兩個點是否相同
bool same(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}

int main() {
    Point p1, p2, p3, p4;

    // 題目會一直輸入到 EOF
    while (cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y) {
        Point repeated, a, b, ans;

        // 找出重複點，另外兩個點用來計算第四點
        if (same(p1, p3)) {
            repeated = p1;
            a = p2;
            b = p4;
        }
        else if (same(p1, p4)) {
            repeated = p1;
            a = p2;
            b = p3;
        }
        else if (same(p2, p3)) {
            repeated = p2;
            a = p1;
            b = p4;
        }
        else {
            repeated = p2;
            a = p1;
            b = p3;
        }

        // 平行四邊形第四點 = 兩個不同點相加 - 重複點
        ans.x = a.x + b.x - repeated.x;
        ans.y = a.y + b.y - repeated.y;

        cout << fixed << setprecision(3) << ans.x << " " << ans.y << endl;
    }

    return 0;
}
