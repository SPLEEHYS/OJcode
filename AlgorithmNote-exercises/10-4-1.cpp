#define INF 0x3fffffff

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct edge {
    int v;
    int weight;
    edge(){}
    edge(int _v, int _weight) {
        v = _v;
        weight = _weight;
    }
} edge;

int n, m, s, t;
vector<vector<edge>> gra;
vector<int> dis;

void SPFA() {
    queue<int> que;
    vector<int> inq(n, 0);
    que.push(s);
    dis[s] = 0;
    while (!que.empty()) {
        int outelem = que.front();
        que.pop();
        inq[outelem] = 0;
        for (int i = 0; i < gra[outelem].size(); i++) {
            int newv = gra[outelem][i].v;
            int wgt = gra[outelem][i].weight;
            if (dis[newv] > dis[outelem] + wgt) {
                dis[newv] = dis[outelem] + wgt;
                if (inq[newv] == 0) {
                    inq[newv] = 1;
                    que.push(newv);
                }
            }
        }
    }
    return;
}

int main() {
    cin >> n >> m >> s >> t;
    gra = vector<vector<edge>>(n);
    dis = vector<int>(n, INF);

    for (int i = 0; i < m; i++) {
        int v1, v2, wei;
        scanf("%d %d %d", &v1, &v2, &wei);
        gra[v1].push_back(edge(v2, wei));
        gra[v2].push_back(edge(v1, wei));
    }

    SPFA();

    dis[t] == INF ? cout << -1 : cout << dis[t];

    return 0;
}