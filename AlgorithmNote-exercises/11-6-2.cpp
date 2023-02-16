#define INF 0x3fffffff
#include<cstdio>
#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
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

int n, m;
vector<vector<edge>> gra;
vector<vector<int>> nextv;
vector<int> maxdis;

int dfs(int x) {
    if (maxdis[x] != -INF) {
        return maxdis[x];
    }
    if (gra[x].size() == 0) {
        maxdis[x] = 1;
        nextv[x].push_back(x);
        assert(nextv[x].size() == 1);
        return 1;
    }

    int rec = -INF;
    for (int i = 0; i < gra[x].size(); i++) {
        int v   = gra[x][i].v;
        int dis = gra[x][i].dis;
        if (rec < dfs(v) + dis) {
            rec = dfs(v) + dis;
            nextv[x].clear();
            nextv[x].push_back(v);
        } else if (rec == dfs(v) + dis) {
            nextv[x].push_back(v);
        }
    }

    maxdis[x] = rec;
    return rec;
}

void trav(int cur, vector<int> &tmppath) {
    if (gra[cur].size() == 0) {
        for (int i = 0; i < tmppath.size(); i++) {
            if (i != 0) {
                printf("->");
            }
            printf("%d", tmppath[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < nextv[cur].size(); i++) {
        int v = nextv[cur][i];
        tmppath.push_back(v);
        trav(v, tmppath);
        tmppath.pop_back();
        break;
    }
}

int main() {
    cin >> n >> m;
    gra = vector<vector<edge>>(n);
    nextv = vector<vector<int>>(n);
    maxdis = vector<int>(n, -INF);
    for (int i = 0; i < m; i++) {
        int v1, v2, dis;
        scanf("%d %d %d", &v1, &v2, &dis);
        gra[v1].push_back(edge(v2, dis));
    }

    int s, rec = -INF;
    for (int i = 0; i < n; i++) {
        int tmp = dfs(i);
        if (rec < tmp) {
            rec = tmp;
            s = i;
        }
    }

    for (int i = 0; i < n; i++) {
        sort(nextv[i].begin(), nextv[i].end());
    }

    vector<int> tmppath;
    tmppath.push_back(s);
    trav(s, tmppath);
    return 0;
}