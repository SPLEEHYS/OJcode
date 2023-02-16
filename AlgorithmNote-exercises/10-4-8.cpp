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

int n, m;
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
            if (min_dis[s][newv] >= dis + min_dis[s][outelem]) { // 必须要有等于号，
                                                                 // 否则当以newv为源点进行最短路搜索时，不会把原先已探测到的较短路顶点放入队列进行松弛。
                min_dis[s][newv] = min_dis[newv][s] = dis + min_dis[s][outelem]; // 由于是无向图，所以可以同时更新两个，从而减少计算量。但必须让判断条件中包含等号。
                if (inq[newv] == 0) {
                    inq[newv] = 1;
                    que.push(newv);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    min_dis = vector<vector<int>>(n, vector<int>(n, INF));
    gra = vector<vector<edge>>(n);

    for (int i = 0; i < m; i++) {
        int v1, v2, dis;
        scanf("%d %d %d", &v1, &v2, &dis);
        gra[v1].push_back(edge(v2, dis));
        gra[v2].push_back(edge(v1, dis));
    }

    for (int i = 0; i < n; i++) {
        SPFA(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j != 0) {
                printf(" ");
            }
            min_dis[i][j] == INF ? printf("-1") : printf("%d", min_dis[i][j]);
        }
        printf("\n");
    }

    return 0;
}