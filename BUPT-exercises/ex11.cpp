// https://www.noobdream.com/DreamJudge/Issue/page/1040/
#include <cstdio>
#include <iostream>
using namespace std;

#define BASE0 0
#define BASE1 (100000 * 0.1)
#define BASE2 (BASE1 + 100000 * 0.075)
#define BASE3 (BASE2 + 200000 * 0.05)
#define BASE4 (BASE3 + 200000 * 0.03)
#define BASE5 (BASE4 + 400000 * 0.015)

int main() {
    double margin, bonus;
    cin >> margin;
    if (margin < 100000) {
        bonus = BASE0;
        bonus += margin * 0.1;
    } else if (margin < 200000) {
        bonus = BASE1;
        bonus += (margin - 100000) * 0.075;
    } else if (margin < 400000) {
        bonus = BASE2;
        bonus += (margin - 200000) * 0.05;
    } else if (margin < 600000) {
        bonus = BASE3;
        bonus += (margin - 400000) * 0.03;
    } else if (margin < 1000000) {
        bonus = BASE4;
        bonus += (margin - 600000) * 0.015;
    } else {
        bonus = BASE5;
        bonus += (margin - 1000000) * 0.01;
    }
    cout << bonus;
    return 0;

}