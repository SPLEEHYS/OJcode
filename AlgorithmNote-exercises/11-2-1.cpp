#define INF 0x3fffffff
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> vec, dp;

int MaxSeq(int i) {
    if (dp[i] != -INF) {
        return dp[i];
    }
    dp[i] = max(vec[i], dp[i - 1] + vec[i]);
    return dp[i];
}

int main() {
    cin >> n;
    dp = vec = vector<int>(n, -INF);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }

    dp[0] = vec[0];

    int res = -INF;
    for (int i = 0; i < n; i++) {
        int tmp = MaxSeq(i);
        if (res < tmp) {
            res = tmp;
        }
    }
    cout << res;
    return 0;
}