#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<cassert>
using namespace std;

typedef pair<int, int> node;

int n, head;
map<int, node> child;
map<int, int> dif;
vector<int> res;

void Insert_BST(int &cur, int val) {
    if (cur == -1) {
        cur = val;
        child[cur].first = -1;
        child[cur].second = -1;
        return;
    }

    if (val < cur) {
        Insert_BST(child[cur].first, val);
    } else {
        Insert_BST(child[cur].second, val);
    }
}

void Cal_dif(int cur, int &height) {
    // 后序遍历求出所有结点的平衡因子保存至dif
    if (cur == -1) {
        height = 0;
        return;
    }
    int lheight, rheight;
    Cal_dif(child[cur].first, lheight);
    Cal_dif(child[cur].second, rheight);
    height = max(lheight, rheight) + 1;
    dif[cur] = lheight - rheight;
}

void Print_dif(int cur) {
    // 求出中序遍历对应的平衡因子序列，保存至res
    assert(cur != -1);
    if (child[cur].first != -1) {
        Print_dif(child[cur].first);
    }
    res.push_back(dif[cur]);
    if (child[cur].second != -1) {
        Print_dif(child[cur].second);
    }
}

int main() {
    cin >> n;
    scanf("%d", &head);
    child[head].first = -1;
    child[head].second = -1;

    for (int i = 1; i < n; i++) {
        int inpu;
        scanf("%d", &inpu);
        Insert_BST(head, inpu);
    }

    int height;
    Cal_dif(head, height);   
    Print_dif(head); 

    for (int i = 0; i < res.size(); i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", res[i]);
    }

    return 0;
}