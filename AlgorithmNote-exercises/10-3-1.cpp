/* Solution 1 */
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> father;

int FindRoot(int x) {
    int rt = x, p = x;
    while (rt != father[rt]) {
        rt = father[rt];
    }

    while (p != rt) {
        int tmp = p;
        p = father[p];
        father[tmp] = rt;
    }
    return rt;
}

int main() {
    cin >> n >> m;
    father = vector<int>(n);
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }


    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        int rt1 = FindRoot(v1);
        int rt2 = FindRoot(v2);
        if (rt1 != rt2) {
            father[rt1] = rt2;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (FindRoot(i) == i) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}