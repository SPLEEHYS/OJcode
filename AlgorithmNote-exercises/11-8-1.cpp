#define INF 0x3fffffff
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> hgt, minc;

int dp(int cur) {
    if (cur >= n - 1) {
        return 0;
    }
    if (minc[cur] != INF) {
        return minc[cur];
    }
    int ret1 = dp(cur + 1) + abs(hgt[cur + 1] - hgt[cur]);
    int ret2 = dp(cur + 2) + abs(hgt[cur + 2] - hgt[cur]);
    minc[cur] = min(ret1, ret2);
    return minc[cur];
}

int main() {
    cin >> n;
    minc = vector<int>(n, INF);
    hgt = vector<int>(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &hgt[i]);
    }
    hgt[n] = hgt[n - 1];
    cout << dp(0);
    return 0;
}