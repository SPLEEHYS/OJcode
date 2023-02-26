// https://www.noobdream.com/DreamJudge/Issue/page/1647/
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ONE   = "00000000000000000000000000000001";
string THREE = "00000000000000000000000000000011";
int T;

string BinAdd(string x, string y) {
    assert(x.size() == y.size());
    int carry = 0, cur;
    string res = "00000000000000000000000000000000";
    for (int i = x.size() - 1; i >= 0; i--) {   
        cur    = ((x[i] - '0') + (y[i] - '0') + carry) % 2;
        carry  = ((x[i] - '0') + (y[i] - '0') + carry) / 2;
        res[i] = cur + '0';
    }
    if (carry == 1) {
        res.insert(res.begin(), '1');
    }
    return res;
}

int main() {
    cin >> T;
    string x;
    while (T--) {
        cin >> x;
        cout << BinAdd(x, ONE) << endl;
        cout << BinAdd(x, THREE) << endl;
    }
    return 0;
}