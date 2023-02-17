#define INF 0x3fffffff
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string str1, str2;
vector<vector<int>> minop;

int dp(int x, int y) {
    if (x == 0 || y == 0) {
        return max(x, y);
    }

    if (minop[x][y] != INF) {
        return minop[x][y];
    }

    if (str1[x - 1] == str2[y - 1]) {
        minop[x][y] = dp(x - 1, y - 1);
        return minop[x][y];
    }

    int ret1 = dp(x - 1, y - 1) + 1;
    int ret2 = dp(x - 1, y) + 1;
    int ret3 = dp(x, y - 1) + 1;
    

    minop[x][y] = min(ret1, min(ret2, ret3));
    return minop[x][y];
}

int main() {
    cin >> str1 >> str2;
    minop = vector<vector<int>>(str1.length() + 1, vector<int>(str2.length() + 1, INF));
    cout << dp(str1.length(), str2.length());
    return 0;
}