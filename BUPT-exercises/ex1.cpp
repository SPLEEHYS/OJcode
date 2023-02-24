// https://www.noobdream.com/DreamJudge/Issue/page/1655/
// 带重边的最短路径
#define INF 0x3fffffff
#include<queue>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef struct edge {
    int v1;
    int v2;
    int dis;
    edge(){}
    edge(int _v1, int _v2, int _dis) {
        v1 = _v1;
        v2 = _v2;
        dis = _dis;
    }
} edge;

vector<vector<vector<int>>> gra;
vector<int> mindis;
int n, src = 1, dst;

void SPFA() {
    queue<int> que;
    vector<int> inq(n + 1, 0);
    mindis[src] = 0;
    que.push(src);
    inq[src] = 1;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        inq[v] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < gra[v][i].size(); j++) {
                if (mindis[i] > mindis[v] + gra[v][i][j]) {
                    mindis[i] = mindis[v] + gra[v][i][j];
                    if (inq[i] == 0) {
                        que.push(i);
                        inq[i] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, k;
        cin >> n >> m >> k;
        dst = n;
        gra = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n + 1, vector<int>(1, INF)));
        mindis = vector<int>(n + 1, INF);
        vector<edge> rec(m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &rec[i].v1, &rec[i].v2, &rec[i].dis);
            gra[rec[i].v1][rec[i].v2].push_back(rec[i].dis);
            gra[rec[i].v2][rec[i].v1].push_back(rec[i].dis);
        }
        SPFA();
        cout << mindis[dst] << endl;

        mindis = vector<int>(n + 1, INF);
        for (int i = 0; i < k; i++) {
            int ind;
            scanf("%d", &ind);
            int v1 = rec[ind - 1].v1;
            int v2 = rec[ind - 1].v2;
            int dis = rec[ind - 1].dis;
            for (int j = 0; j < gra[v1][v2].size(); j++) {
                if (gra[v1][v2][j] == dis) {
                    gra[v1][v2].erase(gra[v1][v2].begin() + j);
                    gra[v2][v1].erase(gra[v2][v1].begin() + j);
                    break;
                }
            }
        }
        SPFA();
        cout << mindis[dst] << endl;
    }
    return 0;
}