#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cassert>
using namespace std;

typedef struct node{
    int first;
    int second;
    int val;
} node;
map<int, node> child;

vector<int> parent;

void FillTree(int cur, int &cnt) {
    assert(cur != -1);
    assert(cnt >= 0 && cnt < parent.size());

    if (child[cur].first != -1) {
        FillTree(child[cur].first, cnt);
    }
    child[cur].val = parent[cnt++];
    if (child[cur].second != -1) {
        FillTree(child[cur].second, cnt);
    }
}

void pretrav(int cur, int head) {
    if (cur == -1) {
        return;
    }

    if (cur != head) {
        printf(" ");
    }
    printf("%d", child[cur].val);
    pretrav(child[cur].first, head);
    pretrav(child[cur].second, head);
}

int main() {
    int n;
    cin >> n;
    parent = vector<int>(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &parent[i]);
    }
    sort(parent.begin(), parent.end());

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &child[i].first, &child[i].second);
    }

    int head = 0, cnt = 0;
    FillTree(head, cnt);

    pretrav(head, head);
    return 0;
}