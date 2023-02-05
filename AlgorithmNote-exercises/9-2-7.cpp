#include <iostream>
#include <stdio.h>
#include <vector>
#include <assert.h>
using namespace std;

typedef pair<int, int> node;

int n, head = -1;
vector<int> flag;
vector<node> child;

void reverse_tree(int cur)
{
    if (cur == -1)
        return;

    reverse_tree(child[cur].first);
    reverse_tree(child[cur].second);
    int tmp = child[cur].first;
    swap(child[cur].first, child[cur].second);
    assert(tmp == -1 || tmp != child[cur].first);
    return;
}

void preorder(int cur)
{
    if (cur == -1)
        return;
    if (cur != head)
        printf(" ");
    printf("%d", cur);
    preorder(child[cur].first);
    preorder(child[cur].second);
}

void _inorder(int cur, int &cnt)
{
    if (cur == -1)
        return;
    _inorder(child[cur].first, cnt);
    if (cnt != 0)
        printf(" ");
    printf("%d", cur);
    _inorder(child[cur].second, ++cnt);
}

void inorder(int head)
{
    int cnt = 0;
    _inorder(head, cnt);
}

int main()
{
    cin >> n;
    flag = vector<int>(n, 0);
    child = vector<node>(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &child[i].first, &child[i].second);
        if (child[i].first != -1)
            flag[child[i].first] = 1;
        if (child[i].second != -1)
            flag[child[i].second] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (flag[i] == 0)
        {
            head = i;
            break;
        }
    }
    assert(head != -1);
    reverse_tree(head);
    preorder(head);
    cout << "\n";
    inorder(head);
    return 0;
}