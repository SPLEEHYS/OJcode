#define INF 0x3fffffff

#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> gra;
vector<int> vis, weight;

int dfs(int cur) {
    vis[cur] = 1;
    int cnt = weight[cur];
    for (int i = 0; i < gra[cur].size(); i++) {
        int newv = gra[cur][i];
        if (vis[newv] == 0) {
            cnt += dfs(newv);
        }
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    gra = vector<vector<int>>(n);
    vis = weight = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        gra[v1].push_back(v2);
        gra[v2].push_back(v1);
    }

    int _max = -INF;
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            _max = max(_max, dfs(i));
        }
    }
    cout << _max;
    return 0;
} 