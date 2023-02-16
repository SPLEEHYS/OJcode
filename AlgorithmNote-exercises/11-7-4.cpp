#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n, V;
vector<int> wgt;
vector<vector<int>> num;

int dp(int sta, int rem) {
    if (sta == n) {
        if (rem != 0) {
            return 0;
        } else {
            return 1;
        }
    }
    if (rem < wgt[sta]) {
        return dp(sta + 1, rem);
    }
    if (num[sta][rem] != -1) {
        return num[sta][rem];
    }

    int ret1 = dp(sta + 1, rem - wgt[sta]) % 10007;
    int ret2 = dp(sta + 1, rem) % 10007;
    num[sta][rem] = (ret1 + ret2) % 10007;
    return num[sta][rem];
}

int main() {
    cin >> n >> V;
    wgt = vector<int>(n);
    num = vector<vector<int>>(n, vector<int>(V + 1, -1));
    for (int i = 0; i < n; i++) {
        scanf("%d", &wgt[i]);
    }
    cout << dp(0, V);
    return 0;
}