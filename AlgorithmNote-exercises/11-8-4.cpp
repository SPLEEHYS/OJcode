#define INF 0x3fffffff
#include<cassert>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<vector<int>> cost, minv;

int dp(int cur, int ban) {
    if (cur == n) {
        return 0;
    }
    if (minv[cur][ban] != INF) {
        return minv[cur][ban];
    }

    int ret1 = INF, ret2 = INF, ret3 = INF;
    if (ban != 1) {
        ret1 = cost[cur][0] + dp(cur + 1, 1);
    }
    if (ban != 2) {
        ret2 = cost[cur][1] + dp(cur + 1, 2);
    }
    if (ban != 3) {
        ret3 = cost[cur][2] + dp(cur + 1, 3);
    }
    minv[cur][ban] = min(ret1, min(ret2, ret3));
    return minv[cur][ban];
}

int main() {
    cin >> n;
    cost = vector<vector<int>>(n, vector<int>(3));
    minv = vector<vector<int>>(n, vector<int>(4, INF));
                    
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }
    cout << dp(0, 0);
    return 0;
}   