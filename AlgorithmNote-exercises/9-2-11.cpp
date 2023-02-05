#define _MAX 0x03ffffff
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <cassert>
using namespace std;

typedef pair<int, int> node;

int n, head = -1;
vector<node> tree;
map<int, int> _rank;
vector<int> inorder;

int find_min(int inlo, int inhi)
{
    int *test = (int *)malloc(sizeof(int));
    int cur_min = _MAX;
    int res = -1;
    for (int i = inlo; i <= inhi; i++)
    {
        if (cur_min > _rank[inorder[i]])
        {
            cur_min = _rank[inorder[i]];
            res = i;
        }
    }
    return res;
}

void BuildTree_li(int inlo, int inhi, int root)
{
    if (root == -1)
    {
        assert(inlo > inhi);
        return;
    }

    int lroot = find_min(inlo, root - 1);
    int rroot = find_min(root + 1, inhi);
    if (lroot == -1)
        tree[inorder[root]].first = -1;
    else
        tree[inorder[root]].first = inorder[lroot];
    if (rroot == -1)
        tree[inorder[root]].second = -1;
    else
        tree[inorder[root]].second = inorder[rroot];

    BuildTree_li(inlo, root - 1, lroot);
    BuildTree_li(root + 1, inhi, rroot);
}

void pretrav(int cur)
{
    if (cur == -1)
        return;
    if (cur != head)
        cout << ' ';
    cout << cur;
    pretrav(tree[cur].first);
    pretrav(tree[cur].second);
}

int main()
{
    cin >> n;
    tree = vector<node>(n);
    inorder = vector<int>(n);
    int inorder_root = -1;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        _rank[tmp] = i;
        if (i == 0)
            head = tmp;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inorder[i]);
        if (inorder[i] == head)
            inorder_root = i;
    }

    BuildTree_li(0, n - 1, inorder_root);
    pretrav(head);
    return 0;
}
