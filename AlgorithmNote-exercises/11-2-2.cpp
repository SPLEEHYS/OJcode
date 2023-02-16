#define INF 0x3fffffff
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> vec, dp, rec;

int MaxSeq(int i) {
    if (dp[i] != -INF) {
        return dp[i];
    }
    if (vec[i] > dp[i - 1] + vec[i]) {
        dp[i] = vec[i];
        rec[i] = i;
    } else {
        dp[i] = dp[i - 1] + vec[i];
        rec[i] = rec[i - 1];
    }
    return dp[i];
}

int main() {
    cin >> n;
    dp = vec = rec = vector<int>(n, -INF);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }

    dp[0] = vec[0];
    rec[0] = 0;

    int res = -INF;
    pair<int, int> trace;
    for (int i = 0; i < n; i++) {
        int tmp = MaxSeq(i);
        if (res < tmp) {
            res = tmp;
            trace.first  = rec[i] + 1;
            trace.second = i + 1;
        }
    }
    cout << res << ' ';
    cout << trace.first << ' ' << trace.second;
    return 0;
}