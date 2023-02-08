#include<cstdio>
#include<iostream>
#include<vector>
#include<cassert>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int> parent;
map<int, int> grade;
map<int, vector<int>> group;

bool cmp(int x1, int x2) {
    return x1 > x2;
}

int FindMax(vector<int> &vec) {
    int _max = vec[0];
    for (int i = 0; i < vec.size(); i++) {
        _max = max(_max, vec[i]);
    }
    return _max;
}

int FindRoot(int x) {
    int rt = x, p = x;
    while (rt != parent[rt]) {
        rt = parent[rt];
    }
    
    while (p != rt) {
        int tmp = p;
        p = parent[p];
        parent[tmp] = rt;
    }

    return rt;
}

void join(int x1, int x2) {
    int rt1 = FindRoot(x1);
    int rt2 = FindRoot(x2);
    parent[rt2] = rt1;
}

int main() {
    int n, m;
    cin >> n >> m;
    parent = vector<int>(n + 1, 0);
    for (int i = 1; i < parent.size(); i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        int inpu;
        scanf("%d", &inpu);
        grade[i] = inpu;
    }

    for (int i = 0; i < m; i++) {
        int x1, x2;
        scanf("%d %d", &x1, &x2);
        join(x1, x2);
    }

    for (int i = 1; i < parent.size(); i++) {
        int rt = FindRoot(i);
        group[rt].push_back(grade[i]);
    }
    cout << group.size() << endl;

    vector<int> res;
    for (map<int, vector<int>>::iterator it = group.begin(); it != group.end(); it++) {
        res.push_back(FindMax(it->second));
    }

    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", res[i]);
    }

    return 0;
}