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
    edge(){}
    edge(int _v, int _dis) {
        v = _v;
        dis = _dis;
    }
} edge;

int n, m, s, t;
double min_avgjam = 1.0 * INF;
vector<vector<edge>> gra;
vector<int> jam, min_dis, optpath;
vector<vector<int>> pre;

void SPFA() {
    queue<int> que;
    vector<int> inq(n, 0);
    que.push(s);
    min_dis[s] = 0;
    inq[s] = 1;
    
    while (!que.empty()) {
        int elem = que.front();
        que.pop();
        inq[elem] = 0;

        for (int i = 0; i < gra[elem].size(); i++) {
            int v = gra[elem][i].v;
            int dis = gra[elem][i].dis;
            if (min_dis[v] > min_dis[elem] + dis) {
                min_dis[v] = min_dis[elem] + dis;
                if (inq[v] == 0) {
                    inq[v] = 1;
                    que.push(v);
                }
                pre[v].clear();
                pre[v].push_back(elem);
            } else if (min_dis[v] == min_dis[elem] + dis) {
                pre[v].push_back(elem);
            }
        }
    }
}

void DFS(int cur, vector<int> &tmppath, int cnt_jam, int n) {
    if (cur == s && min_avgjam > (1.0 * cnt_jam / n)) {
        min_avgjam = 1.0 * cnt_jam / n;
        optpath = tmppath;
        return;
    }

    for (int i = 0; i < pre[cur].size(); i++) {
        int next = pre[cur][i];
        tmppath.push_back(next);
        DFS(next, tmppath, cnt_jam + jam[next], n + 1);
        tmppath.pop_back();
    }
}

int main() {
    cin >> n >> m >> s >> t;
    gra = vector<vector<edge>>(n);
    min_dis = vector<int>(n, INF);
    jam = vector<int>(n);
    pre = vector<vector<int>>(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &jam[i]);
    }
    for (int i = 0; i < m; i++) {
        int v1, v2, dis;
        scanf("%d %d %d", &v1, &v2, &dis);
        gra[v1].push_back(edge(v2, dis));
        gra[v2].push_back(edge(v1, dis));
    }

    SPFA();
    vector<int> tmppath;
    tmppath.push_back(t);
    DFS(t, tmppath, jam[t], 1);

    cout << min_dis[t] << " ";
    for (int i = optpath.size() - 1; i >= 0; i--) {
        printf("%d", optpath[i]);
        if (i != 0) {
            printf("->");
        }
    }
    return 0;
}