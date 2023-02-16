#define INF 0x6fffffff
#include<cmath>
#include<cassert>
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
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
vector<vector<int>> nextv;
vector<vector<edge>> gra;
set<pair<int, int>> bucket;

int dp(int x) {
    if (max_dis[x] != -INF) {
        return max_dis[x];
    }
    if (gra[x].size() == 0) {
        max_dis[x] = 0;
        nextv[x].push_back(-1);
        return max_dis[x];
    }

    int maxvalue = 0;
    for (int i = 0; i < gra[x].size(); i++) {
        int dis = gra[x][i].dis;
        int v   = gra[x][i].v;
        if (inflag[v] == 1) {
            return INF;
        }

        inflag[v] = 1;
        int disv = dp(v);
        inflag[v] = 0;

        if (disv == INF) {
            return INF;
        }
        if (maxvalue < dis + disv) {
            maxvalue = dis + disv;
            nextv[x].clear();
            nextv[x].push_back(v);
        } else if (maxvalue == dis + disv) {
            nextv[x].push_back(v);
        }
    }

    max_dis[x] = maxvalue;
    return maxvalue;
}

void dfs(int cur) {
    if (nextv[cur][0] == -1) {
        assert(nextv[cur].size() == 1);
        return;
    }
    for (int i = 0; i < nextv[cur].size(); i++) {
        bucket.insert(make_pair(cur, nextv[cur][i]));
        dfs(nextv[cur][i]);
    }
}

int main() {
    cin >> n >> m;
    max_dis = vector<int>(n, -INF);
    inflag = vector<int>(n, 0);
    nextv = vector<vector<int>>(n);
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
        cout << "Yes\n";
        dfs(s);
        for (set<pair<int, int>>::iterator it = bucket.begin(); it != bucket.end(); it++) {
            printf("%d %d\n", (*it).first, (*it).second);
        }
    } else {
        cout << "No";
    }
    return 0;
}