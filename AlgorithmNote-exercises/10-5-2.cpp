#define INF 0x3fffffff
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct edge {
    int v1;
    int v2;
    int dis;
    edge () {}
    edge (int _v1, int _v2, int _dis) {
        v1 = _v1;
        v2 = _v2;
        dis = _dis;
    }
    friend bool operator < (edge x1, edge x2) {
        return x1.dis > x2.dis;
    }
} edge;

int n, m, mincost = INF;
vector<edge> vec;
priority_queue<edge> heap;
vector<int> father;

int Root(int x) {
    int rt = x, ptr = x;
    while (rt != father[rt]) {
        rt = father[rt];
    }

    while (ptr != rt) {
        int tmp = ptr;
        ptr = father[ptr];
        father[tmp] = rt;
    }

    return rt;
}

void Kruskal() {
    int nsel = 0, acc = 0;
    while (!heap.empty()) {
        int v1 = heap.top().v1;
        int v2 = heap.top().v2;
        int dis = heap.top().dis;
        heap.pop();

        int rt1 = Root(v1);
        int rt2 = Root(v2);

        if (rt1 == rt2) {
            continue;
        }

        nsel++;
        acc += dis;
        father[rt1] = rt2;
    }
    if (nsel == n - 1) {
        mincost = acc;
    }
}

int main() {
    cin >> n >> m;
    vec = vector<edge>(m);
    father = vector<int>(n);
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &vec[i].v1, &vec[i].v2, &vec[i].dis);
    }
    heap = priority_queue<edge>(vec.begin(), vec.end());

    Kruskal();
    mincost == INF ? cout << -1 : cout << mincost;
    return 0;
}
