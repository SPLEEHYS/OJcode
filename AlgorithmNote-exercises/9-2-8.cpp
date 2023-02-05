#include <stdio.h>
#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;

typedef pair<int, int> node;

int n, head;
vector<int> preorder, inorder, postorder;
vector<node> tree;

int BuildTree_pi(int prelo, int prehi, int inlo, int inhi)
{
    if (prelo > prehi || inlo > inhi)
        return -1;
    int head = preorder[prelo];
    int piv = inlo;
    while (inorder[piv] != head)
    {
        assert(piv <= inhi);
        piv++;
    }
    int leftlen = piv - inlo;
    assert(leftlen >= 0);

    int lc = BuildTree_pi(prelo + 1, prelo + leftlen, inlo, piv - 1);
    int rc = BuildTree_pi(prelo + leftlen + 1, prehi, piv + 1, inhi);
    tree[head].first = lc;
    tree[head].second = rc;
    return head;
}

void pretrav(int cur)
{
    if (cur == -1)
        return;
    if (cur != head)
        printf(" ");
    cout << cur;
    pretrav(tree[cur].first);
    pretrav(tree[cur].second);
}

void _postrav(int cur, int &cnt)
{
    if (cur == -1)
        return;
    _postrav(tree[cur].first, cnt);
    _postrav(tree[cur].second, cnt);

    if (cnt != 0)
        cout << " ";
    cout << cur;
    cnt++;
}

void postrav(int cur)
{
    int cnt = 0;
    _postrav(cur, cnt);
}

int main()
{
    int n;
    cin >> n;
    preorder = inorder = vector<int>(n);
    tree = vector<node>(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);
    head = BuildTree_pi(0, n - 1, 0, n - 1);
    postrav(head);
    return 0;
}