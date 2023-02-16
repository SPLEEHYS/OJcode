#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n, V;
vector<vector<int>> maxv;
vector<int> wgt, val;

int dp(int sta, int rem) {
    if (sta == n) {
        return 0;
    }
    if (rem < wgt[sta]) {
        return dp(sta + 1, rem);
    }
    if (maxv[sta][rem] != -1) {
        return maxv[sta][rem];
    }

    int ret1 = val[sta] + dp(sta, rem - wgt[sta]);
    int ret2 = dp(sta + 1, rem);
    maxv[sta][rem] = max(ret1, ret2);
    return maxv[sta][rem];
}

int main() {
    cin >> n >> V;
    maxv = vector<vector<int>>(n, vector<int>(V + 1, -1));
    wgt = val = vector<int>(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &wgt[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    cout << dp(0, V);
    return 0;
}