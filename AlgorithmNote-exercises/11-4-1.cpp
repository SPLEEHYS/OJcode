#define INF 0x3fffffff
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

string x1, x2;
vector<vector<int>> maxlen;

int DP(int n1, int n2) {
    if (maxlen[n1][n2] != -INF) {
        return maxlen[n1][n2];
    }
    if (x1[n1 - 1] == x2[n2 - 1]) { // 注意字符串序号是从0开始的
        maxlen[n1][n2] = DP(n1 - 1, n2 - 1) + 1;
    } else {
        maxlen[n1][n2] = max(DP(n1 - 1, n2), DP(n1, n2 - 1));
    }
    return maxlen[n1][n2];
}

int main() {
    cin >> x1 >> x2;
    maxlen = vector<vector<int>>(x1.length() + 1, vector<int>(x2.length() + 1, -INF));
    for (int i = 0; i <= x1.length(); i++) {
        maxlen[i][0] = 0;
    }
    for (int i = 0; i <= x2.length(); i++) {
        maxlen[0][i] = 0;
    }
    cout << DP(x1.length(), x2.length());
    return 0;
}