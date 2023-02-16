#include<cassert>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n, V;
vector<vector<int>> maxv, choice;
vector<int> wgt, val;

int dp(int sta, int rem) {
    if (sta == n) {
        return 0;
    }
    if (rem < wgt[sta]) {
        choice[sta][rem] = 0;
        return dp(sta + 1, rem);
    }
    if (maxv[sta][rem] != -1) {
        return maxv[sta][rem];
    }

    int ret1 = val[sta] + dp(sta + 1, rem - wgt[sta]);
    int ret2 = dp(sta + 1, rem);
    ret1 >= ret2 ? choice[sta][rem] = 1 : choice[sta][rem] = 0;
    maxv[sta][rem] = max(ret1, ret2);
    return maxv[sta][rem];
}

int main() {
    cin >> n >> V;
    maxv = choice = vector<vector<int>>(n, vector<int>(V + 1, -1));
    wgt = val = vector<int>(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &wgt[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    cout << dp(0, V) << endl;

    vector<int> res;
    int sta = 0, rem = V;
    while (sta != n) {
        if (choice[sta][rem] == 1) {
            res.push_back(sta + 1);
            rem -= wgt[sta];
        }
        sta++;
    }
    for (int i = 0; i < res.size(); i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", res[i]);
    }
    return 0;
}