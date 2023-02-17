#define INF 0x3fffffff
#include<cassert>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<vector<int>> wgt, maxv;

int dp(int r, int c) {
    assert(r < n && c < m);
    if (maxv[r][c] != -INF) {
        return maxv[r][c];
    }
    if (r == n - 1 && c == m - 1) {
        maxv[r][c] = wgt[n - 1][m - 1];
        return maxv[r][c];
    }

    int ret1 = -INF, ret2 = -INF;
    if (r + 1 < n) {
        ret1 = wgt[r][c] + dp(r + 1, c);
    }
    if (c + 1 < m) {
        ret2 = wgt[r][c] + dp(r, c + 1);
    }
    assert(!(ret1 == -INF && ret2 == -INF));
    maxv[r][c] = max(ret1, ret2);
    return maxv[r][c];
}

int main() {
    cin >> n >> m;
    wgt = maxv = vector<vector<int>>(n, vector<int>(m, -INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &wgt[i][j]);
        }
    }
    cout << dp(0, 0);
    return 0;
}