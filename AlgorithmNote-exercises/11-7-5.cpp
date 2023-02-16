#include<cassert>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n, V;
vector<int> wgt, val;
vector<vector<int>> maxv, num;

int dp(int sta, int rem) {
    if (sta == n) {
        maxv[sta][rem] = 0;
        num[sta][rem] = 1;
        return maxv[sta][rem];
    }    
    if (rem < wgt[sta]) {
        int ret = dp(sta + 1, rem);
        num[sta][rem] = num[sta + 1][rem];
        return ret;
    }
    if (maxv[sta][rem] != -1) {
        assert(num[sta][rem] != -1);
        return maxv[sta][rem];
    }

    int ret1 = val[sta] + dp(sta + 1, rem - wgt[sta]);
    int ret2 = dp(sta + 1, rem);
    assert(num[sta + 1][rem - wgt[sta]] != -1);
    assert(num[sta + 1][rem] != -1);

    if (ret1 > ret2) {
        maxv[sta][rem] = ret1;
        num[sta][rem] = num[sta + 1][rem - wgt[sta]];
    } else if (ret1 < ret2) {
        maxv[sta][rem] = ret2;
        num[sta][rem] = num[sta + 1][rem];
    } else {
        maxv[sta][rem] = ret1;
        num[sta][rem] = (num[sta + 1][rem] + num[sta + 1][rem - wgt[sta]]) % 10007;
    }
    return maxv[sta][rem];
}

int main() {
    cin >> n >> V;
    wgt = val = vector<int>(n);
    maxv = num = vector<vector<int>>(n + 1, vector<int>(V + 1, -1));
    for (int i = 0; i < n; i++) {
        scanf("%d", &wgt[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    dp(0, V);
    cout << maxv[0][V] << ' ' << num[0][V];
    return 0;
}