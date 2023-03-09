// https://www.noobdream.com/DreamJudge/Issue/page/1240/
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

#define isEmpty(x) (x == ' ' || x == '\t' || x == '\n' || x == '\r')

int main() {
    string str = " ";
    char cr;
    while ((cr = getchar()) != EOF) {
        if (isEmpty(str.back()) && (cr >= 'a' && cr <= 'z')) {
            cr = cr - 32;
        }
        str.insert(str.end(), cr);
    }
    str.erase(0, 1);
    cout << str;
    return 0;
}