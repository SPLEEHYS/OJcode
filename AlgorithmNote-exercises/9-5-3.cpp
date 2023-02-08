#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cassert>
#include<cmath>
using namespace std;

typedef struct node {
    int left = -1;
    int right = -1;
    int lheight = 0;
    int rheight = 0;
} node;

int head;
map<int, node> tree;


int Height(int cur) {
    if (cur == -1) {
        return 0;
    } else {
        return max(tree[cur].lheight, tree[cur].rheight) + 1;
    }
}

int tune123(int n1, int n2, int n3, int t1, int t2, int t3, int t4) {
    tree[n1].left = t1;
    tree[n1].right = t2;
    tree[n1].lheight = Height(t1);
    tree[n1].rheight = Height(t2);

    tree[n3].left = t3;
    tree[n3].right = t4;
    tree[n3].lheight = Height(t3);
    tree[n3].rheight = Height(t4);

    tree[n2].left = n1;
    tree[n2].right = n3;
    tree[n2].lheight = Height(n1);
    tree[n2].rheight = Height(n3);

    return n2;
}

void adjust(int &cur) {
    int lchild = tree[cur].left;
    int rchild = tree[cur].right;

    if (tree[cur].lheight - tree[cur].rheight == 2) {    
        if (tree[lchild].lheight > tree[lchild].rheight) {
            // LL型
            int llchild = tree[lchild].left;
            cur = tune123(llchild, lchild, cur, 
                          tree[llchild].left, 
                          tree[llchild].right, 
                          tree[lchild].right, 
                          tree[cur].right);
        } else {
            // LR型
            int lrchild = tree[lchild].right;
            cur = tune123(lchild, lrchild, cur, 
                          tree[lchild].left, 
                          tree[lrchild].left, 
                          tree[lrchild].right, 
                          tree[cur].right);
        }
    }
    else {
        if (tree[rchild].rheight > tree[rchild].lheight) {
            // RR型
            int rrchild = tree[rchild].right;
            cur = tune123(cur, rchild, rrchild, 
                          tree[cur].left, 
                          tree[rchild].left, 
                          tree[rrchild].left, 
                          tree[rrchild].right);
        } else {
            // RL型
            int rlchild = tree[rchild].left;
            cur = tune123(cur, rlchild, rchild, 
                          tree[cur].left, 
                          tree[rlchild].left, 
                          tree[rlchild].right, 
                          tree[rchild].right);
        }
    }
}

int Insert_AVL(int &cur, int val) {
    if (cur == -1) {
        cur = val;
        tree[val];
        return 1;
    }
    
    if (val < cur) {
        int lh = Insert_AVL(tree[cur].left, val);
        tree[cur].lheight = lh;
    } else {
        int rh = Insert_AVL(tree[cur].right, val); 
        tree[cur].rheight = rh;
    }
    if (abs(tree[cur].lheight - tree[cur].rheight) > 1) {
        adjust(cur);
    }
    return max(tree[cur].lheight, tree[cur].rheight) + 1;
}

void pretrav(int cur, int head) {
    if (cur == -1) {
        return;
    }

    if (cur != head) {
        printf(" ");
    }
    printf("%d", cur);
    pretrav(tree[cur].left, head);
    pretrav(tree[cur].right, head);
}

int main() {
    int n;
    cin >> n;
    cin >> head;
    tree[head];
    for (int i = 1; i < n; i++) {
        int inpu;
        scanf("%d", &inpu);
        Insert_AVL(head, inpu);
    }

    pretrav(head, head);
    return 0;
}