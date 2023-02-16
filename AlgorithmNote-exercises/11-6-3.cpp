#define INF 0x3fffffff
#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

typedef struct edge {
    int v;
    int dis;
    edge(){}
    edge(int _v, int _dis) {
        v   = _v;
        dis = _dis;
    }
} edge;

int n, m, t;
vector<int> maxdis;
vector<vector<edge>> gra;

int dp(int x) {   
    if (maxdis[x] != -INF) {
        return maxdis[x];
    }
    if (x == t) {
        maxdis[x] = 0;
        return maxdis[x];
    }
    if (gra[x].size() == 0) {
        maxdis[x] = -(INF - 1);
        return maxdis[x];
    }

    int rec = -INF;
    for (int i = 0; i < gra[x].size(); i++) {
        int v   = gra[x][i].v;
        int dis = gra[x][i].dis;
        rec = max(rec, dp(v) + dis);
    }
    maxdis[x] = rec;
    return maxdis[x];
}

int main() {
    cin >> n >> m >> t;
    maxdis = vector<int>(n, -INF);
    gra = vector<vector<edge>>(n);
    for (int i = 0; i < m; i++) {
        int v1, v2, dis;
        scanf("%d %d %d", &v1, &v2, &dis);
        gra[v1].push_back(edge(v2, dis));
    }

    int rec = -INF;
    for (int i = 0; i < n; i++) {
        rec = max(rec, dp(i));
    }
    cout << rec;
    return 0;
}