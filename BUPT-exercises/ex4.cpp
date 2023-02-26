// https://www.noobdream.com/DreamJudge/Issue/page/1654/
// 坑：题目有大于n的结点编号，但只输入了结点1-n的孩子
#define MAXN 1000
#define INF 0x3fffffff
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
    int left = -1;
    int right = -1;
    int height = INF;
    int stime = INF;
    int etime = INF;
}node;

vector<node> tree;
int _time = 0;

void cal(int cur, int height) {
    if (cur == -1) {
        return;
    }

    tree[cur].height = height;
    tree[cur].stime  = _time;

    _time++;
    cal(tree[cur].left, height + 1);
    _time++;
    cal(tree[cur].right, height + 1);

    tree[cur].etime = _time;
}

#define Enclose(v, left, right) (tree[v].stime <= left && tree[v].etime >= right)

int LCA(int rt, int left, int right) {
    if (Enclose(tree[rt].left, left, right)) {
        return LCA(tree[rt].left, left, right);
    } else if (Enclose(tree[rt].right, left, right)) {
        return LCA(tree[rt].right, left, right);
    } else {
        return rt;
    }
}

#undef Enclose

#define Enclose(x, y) (tree[x].stime <= tree[y].stime && tree[x].etime >= tree[y].etime)

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        tree = vector<node>(MAXN);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &tree[i].left, &tree[i].right);
        }
        cal(1, 0);
        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            // 利用stime和etime可以判断两个结点是否在一条直线上，如果不在一条直线上，再用LCA求出公共点
            if (Enclose(x, y) || Enclose(y, x)) {
                printf("%d\n", abs(tree[x].height - tree[y].height));
            } else {
                int v = LCA(1, min(tree[x].stime, tree[y].stime), max(tree[x].etime, tree[y].etime));
                printf("%d\n", tree[x].height + tree[y].height - 2 * tree[v].height);
            }
        }
    }
    return 0;
}