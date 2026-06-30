#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {

    map<string, string> dict;
    string line;

    // 建立字典，直到遇到空白行
    while (getline(cin, line)) {

        if (line.empty())
            break;

        string english, foreign;
        stringstream ss(line);

        ss >> english >> foreign;

        // 外文 -> 英文
        dict[foreign] = english;
    }

    // 查詢直到 EOF
    while (getline(cin, line)) {

        if (dict.count(line))
            cout << dict[line] << endl;
        else
            cout << "eh" << endl;
    }

    return 0;
}
