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

int n, m, ret = INF;
vector<vector<edge>> gra;

void Prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    vector<int> min_dis = vector<int>(n, INF);
    vector<int> inset = vector<int>(n, 0);
    int n_in = 0, cnt = 0;
    min_dis[0] = 0;
    heap.push(make_pair(0, 0));

    while (!heap.empty()) {
        int elem = heap.top().second;
        heap.pop();
        if (inset[elem] == 1) {
            continue;
        }

        inset[elem] = 1;
        n_in++;
        cnt += min_dis[elem];

        for (int i = 0; i < gra[elem].size(); i++) {
            int v = gra[elem][i].v;
            int dis = gra[elem][i].dis;
            if (inset[v] == 0 && min_dis[v] > dis) {
                min_dis[v] = dis;
                heap.push(make_pair(min_dis[v], v));
            }
        }
    }

    if (n_in == n) {
        ret = min(cnt, ret);
    }

}

int main() {
    cin >> n >> m;
    gra = vector<vector<edge>>(n);
    for (int i = 0; i < m; i++) {
        int v1, v2, dis;
        scanf("%d %d %d", &v1, &v2, &dis);
        gra[v1].push_back(edge(v2, dis));
        gra[v2].push_back(edge(v1, dis));
    }

    Prim();
    ret == INF ? cout << -1 : cout << ret;
    return 0;
}