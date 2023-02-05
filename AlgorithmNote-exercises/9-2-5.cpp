#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

typedef struct node
{
    int left;
    int right;
} node;

int n, head = -1;
vector<node> child;
vector<int> flag;

int Height(int cur)
{
    if (cur == -1)
        return 0;

    int lh = Height(child[cur].left);
    int rh = Height(child[cur].right);
    return max(lh, rh) + 1;
}

int main()
{
    cin >> n;
    child = vector<node>(n + 1);
    flag = vector<int>(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> child[i].left;
        cin >> child[i].right;
        flag[child[i].left] = 1;
        if (child[i].right >= 0)
            flag[child[i].right] = 1;
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

    cout << Height(head);
    return 0;
}
