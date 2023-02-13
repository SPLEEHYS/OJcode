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
    edge(int _v, int _dis) {
        v = _v;
        dis = _dis;
    }
} edge;

int n, m, s, t;
vector<vector<edge>> gra;
vector<vector<edge>> pre;
vector<int> mindis;

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
            if (mindis[v] > mindis[outelem] + dis) {
                mindis[v] = mindis[outelem] + dis;
                if (inq[v] == 0) {
                    inq[v] = 1;
                    que.push(v);
                }
                pre[v].clear();
                pre[v].push_back(edge(outelem, dis));
            } else if (mindis[v] == mindis[outelem] + dis) {
                pre[v].push_back(edge(outelem, dis));
            }
        }
    }
}

int main() {
    cin >> n >> m >> s >> t;
    gra = pre = vector<vector<edge>>(n);
    mindis = vector<int>(n, INF);
    for (int i = 0; i < m; i++) {
        int v1, v2, w1;
        scanf("%d %d %d", &v1, &v2, &w1);
        gra[v1].push_back(edge(v2, w1));
        gra[v2].push_back(edge(v1, w1));
    }

    SPFA();

    vector<int> path;
    int p = t;
    while (1) {
        path.push_back(p);
        p = pre[p][0].v;
        if (p == s) {
            break;
        }
    }
    path.push_back(s);

    cout << mindis[t] << ' ';
    for (int i = path.size() - 1; i >= 0; i--) {
        if (i != path.size() - 1) {
            printf("->");
        }
        printf("%d", path[i]);
    }

    return 0;
}