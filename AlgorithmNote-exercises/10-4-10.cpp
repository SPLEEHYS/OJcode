#define INF 0x3fffffff

#include<cassert>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
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

int n, m, k;
vector<vector<int>> min_dis;
vector<vector<edge>> gra;

void SPFA(int s) {
    queue<int> que;
    vector<int> inq(n, 0);
    min_dis[s][s] = 0;
    que.push(s);
    inq[s] = 1;

    while (!que.empty()) {
        int outelem = que.front();
        que.pop();
        inq[outelem] = 0;

        for (int i = 0; i < gra[outelem].size(); i++) {
            int newv = gra[outelem][i].v;
            int dis = gra[outelem][i].dis;
            if (min_dis[s][newv] >= dis + min_dis[s][outelem]) {
                min_dis[s][newv] = min_dis[newv][s] = dis + min_dis[s][outelem];
                if (inq[newv] == 0) {
                    inq[newv] = 1;
                    que.push(newv);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    min_dis = vector<vector<int>>(n, vector<int>(n, INF));
    gra = vector<vector<edge>>(n);

    for (int i = 0; i < m; i++) {
        int v1, v2, dis;
        scanf("%d %d %d", &v1, &v2, &dis);
        gra[v1].push_back(edge(v2, dis));
        gra[v2].push_back(edge(v1, dis));
    }

    vector<int> bucket = vector<int>(k);
    int optcity = -1, res = INF;

    for (int i = 0; i < k; i++) {
        scanf("%d", &bucket[i]);
    }
    for (int i = 0; i < k; i++) {
        SPFA(bucket[i]);
        int s = bucket[i];
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += min_dis[s][j];
        }
        if (res > cnt) {
            res = cnt;
            optcity = s;
        }
    }

    cout << optcity << ' ' << res;

    return 0;
}