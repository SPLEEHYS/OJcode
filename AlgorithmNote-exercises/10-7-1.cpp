#define INF 0x6fffffff
#include<cmath>
#include<cassert>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

typedef struct edge {
    int v;
    int dis;
    edge(){}
    edge(int _v, int _dis) {
        v = _v;
        dis = _dis;
    }
} edge;

int n, m;
vector<int> max_dis, inflag;
vector<vector<edge>> gra;

int dp(int x) {
    if (max_dis[x] != -INF) {
        return max_dis[x];
    }

    int ret = 0;
    for (int i = 0; i < gra[x].size(); i++) {
        int dis = gra[x][i].dis;
        int v   = gra[x][i].v;
        if (inflag[v] == 1) {
            return INF;
        }

        inflag[v] = 1;
        int maxv = dp(v);
        if (maxv == INF) {
            return INF;
        }
        ret = max(ret, dis + maxv);
        inflag[v] = 0;
    }

    max_dis[x] = ret;
    return ret;
}

int main() {
    cin >> n >> m;
    max_dis = vector<int>(n, -INF);
    inflag = vector<int>(n, 0);
    gra = vector<vector<edge>>(n);
    vector<int> flag(n, 0);
    for (int i = 0; i < m; i++) {
        int v1, v2, dis;
        scanf("%d %d %d", &v1, &v2, &dis);
        gra[v1].push_back(edge(v2, dis));
        flag[v2] = 1;
    }
    int cnt = 0;
    int s = -1;
    for (int i = 0; i < n; i++) {
        if (flag[i] == 0) {
            cnt++;
            s = i;
        }
    }
    assert(cnt == 1);

    inflag[s] = 1;
    int res = dp(s);
    if (res != INF) {
        cout << "Yes\n" << res;
    } else {
        cout << "No";
    }
    return 0;
}