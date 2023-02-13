#define INF 0x3fffffff
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
using namespace std;

typedef struct edge {
    int v;
    int dis;
    int cost;
    edge(){}
    edge(int _v, int _dis, int _cost) {
        v = _v;
        dis = _dis;
        cost = _cost;
    }
} edge;

int n, m, s, t;
vector<vector<edge>> gra;
vector<vector<edge>> pre;
vector<int> mindis;
int mincost = INF;

void SPFA() {
    queue<int> que;
    vector<int> inq(n, 0);
    que.push(s);
    mindis[s] = 0;
    inq[s] = 1;
    while (!que.empty()) {
        int outelem = que.front();
        que.pop();
        inq[outelem] = 0;

        for (int i = 0; i < gra[outelem].size(); i++) {
            int v = gra[outelem][i].v;
            int dis = gra[outelem][i].dis;
            int cost = gra[outelem][i].cost;
            if (mindis[v] > mindis[outelem] + dis) {
                mindis[v] = mindis[outelem] + dis;
                if (inq[v] == 0) {
                    inq[v] = 1;
                    que.push(v);
                }
                pre[v].clear();
                pre[v].push_back(edge(outelem, dis, cost));
            } else if (mindis[v] == mindis[outelem] + dis) {
                pre[v].push_back(edge(outelem, dis, cost));
            }
        }
    }
}

void DFS(int cur, int coscnt) {
    if (coscnt > mincost) {
        return;
    }
    if (cur == s) {
        assert(mincost >= coscnt);
        mincost = coscnt;
        return;
    }
    for (int i = 0; i < pre[cur].size(); i++) {
        DFS(pre[cur][i].v, coscnt + pre[cur][i].cost);
    }
}


int main() {
    cin >> n >> m >> s >> t;
    gra = pre = vector<vector<edge>>(n);
    mindis = vector<int>(n, INF);
    for (int i = 0; i < m; i++) {
        int v1, v2, w1, w2;
        scanf("%d %d %d %d", &v1, &v2, &w1, &w2);
        gra[v1].push_back(edge(v2, w1, w2));
        gra[v2].push_back(edge(v1, w1, w2));
    }

    SPFA();
    DFS(t, 0);

    printf("%d %d", mindis[t], mincost);
    return 0;
}