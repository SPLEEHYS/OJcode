// https://www.noobdream.com/DreamJudge/Issue/page/1043/
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int a, n;
    cin >> a >> n;
    int64_t res = 0, plus = 0;

    for (int i = 0 ; i < n; i++) {
        plus +=  a * int64_t(pow(10.0, double(i)));
        res += plus;
    }
    cout << res;
    return 0;
}