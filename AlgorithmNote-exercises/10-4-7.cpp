#define INF 0x3fffffff
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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
vector<vector<edge>> gra;
vector<vector<edge>> pre;
vector<int> mindis;
vector<vector<int>> path;

bool cmp(vector<int> vec1, vector<int> vec2) {
    reverse(vec1.begin(), vec1.end());
    reverse(vec2.begin(), vec2.end());
    return vec1 < vec2;
}

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

void DFS(int cur, vector<int> &tmppath) {
    if (cur == s) {
        path.push_back(tmppath);
        return;
    }
    for (int i = 0; i < pre[cur].size(); i++) {
        tmppath.push_back(pre[cur][i].v);
        DFS(pre[cur][i].v, tmppath);
        tmppath.pop_back();
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
    vector<int> tmppath;
    tmppath.push_back(t);
    DFS(t, tmppath);
    sort(path.begin(), path.end(), cmp);

    cout << path.size() << endl;
    for (int i = 0; i < path.size(); i++) {
        for (int j = path[i].size() - 1; j >= 0; j--) {
            if (j != path[i].size() - 1) {
                printf("->");
            }
            printf("%d", path[i][j]);
        }
        printf("\n");
    }

    return 0;
}