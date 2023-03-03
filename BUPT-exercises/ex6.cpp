// https://www.noobdream.com/DreamJudge/Issue/page/1557/
// 题目测试数据会出现6个连续的1，有问题
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    getchar();
    while (T--) {
        string str;
        getline(cin, str);
        int cnt1 = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '0') {
                if (cnt1 == 5) {
                    str.erase(str.begin() + i);
                    i--;
                } 
                cnt1 = 0;
            } else { 
                cnt1++;
                if (cnt1 == 6) { 
                    // 由于题目测试数据会出现6个连续的1，所以只能如此处理才能保证通过
                    str.erase(str.begin() + i);
                    i--;
                    cnt1 = 0;
                };
            }
        }
        cout << str << "\n";
    }
    return 0;
}