#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef pair<int, int> node;

int head = -1;

map<int, node> child;

void Insert_BST(int &rt, int val) {
    if (rt == -1) {
        rt = val;
        child[rt].first = -1;
        child[rt].second = -1;
        return;
    }
    if (val < rt) {
        Insert_BST(child[rt].first, val);
    } else {
        Insert_BST(child[rt].second, val);
    }
    return;
}

void pretrav(int cur) {
    if (cur == -1) {
        return;
    }
    if (cur != head) {
        printf(" ");
    }
    printf("%d", cur);
    pretrav(child[cur].first);
    pretrav(child[cur].second);
    return;
}

int main() {
    int n;
    cin >> n;

    scanf("%d", &head);
    child[head].first = -1;
    child[head].second = -1;

    for (int i = 1; i < n; i++) {
        int inpu;
        scanf("%d", &inpu);
        Insert_BST(head, inpu);
    }

    pretrav(head);

    return 0;
}
