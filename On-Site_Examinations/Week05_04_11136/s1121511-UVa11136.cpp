#include <iostream>
#include <set>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {
    int n;

    // 題目以 n = 0 結束
    while (cin >> n && n) {

        multiset<int> bills;   // 儲存所有尚未兌換的帳單
        long long ans = 0;     // 總收入，需使用 long long

        while (n--) {
            int k;
            cin >> k;   // 今天收到幾張帳單

            // 將今天所有帳單加入 multiset
            while (k--) {
                int x;
                cin >> x;
                bills.insert(x);
            }

            // 取得最小帳單
            auto low = bills.begin();

            // 取得最大帳單
            auto high = prev(bills.end());

            // 累加今天收入
            ans += (*high - *low);

            // 先刪除最小，再刪除最大
            bills.erase(low);

            high = prev(bills.end()); // 更新最大值 iterator
            bills.erase(high);
        }

        cout << ans << endl;
    }

    return 0;
}
