#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

typedef pair<int, int> node;

int n, k1, k2, head = -1;
vector<node> child;
vector<int> flag;

int LCA(int cur, int &res)
{
    if (cur == -1)
        return 0;
    if (res != -1)
        return 3;
    int flag1 = LCA(child[cur].first, res);
    int flag2 = LCA(child[cur].second, res);
    int flag3 = 0;
    if (cur == k1)
        flag3 += 1;
    if (cur == k2)
        flag3 += 2;
    if (flag3 == 3)
        res = cur;
    if (res != -1)
        return 3;
    if (flag1 + flag2 + flag3 == 3)
    {
        res = cur;
        return 3;
    }
    if (flag1 == 0)
        return flag2 + flag3;
    if (flag2 == 0)
        return flag1 + flag3;
}

int main()
{
    cin >> n >> k1 >> k2;
    child = vector<node>(n);
    flag = vector<int>(n, 0);
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
    int res = -1;
    LCA(head, res);
    cout << res;
    return 0;
}