#include <iostream>
#include <map>
#include <string>
using namespace std;

// Author: 林楷恩 (1121511)
// Reference: ChatGPT 協助整理解法、註解與程式架構，本人理解後完成。

int main() {

    // 建立問候語與語言的對照表
    map<string, string> language;

    language["HELLO"] = "ENGLISH";
    language["HOLA"] = "SPANISH";
    language["HALLO"] = "GERMAN";
    language["BONJOUR"] = "FRENCH";
    language["CIAO"] = "ITALIAN";
    language["ZDRAVSTVUJTE"] = "RUSSIAN";

    string word;
    int caseNumber = 1;

    // 持續讀入直到遇到 '#'
    while (cin >> word && word != "#") {

        cout << "Case " << caseNumber << ": ";

        // 如果找到對應語言
        if (language.count(word)) {
            cout << language[word] << endl;
        }
        // 否則輸出 UNKNOWN
        else {
            cout << "UNKNOWN" << endl;
        }

        caseNumber++;
    }

    return 0;
}
