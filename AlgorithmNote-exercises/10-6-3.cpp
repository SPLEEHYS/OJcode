#include<cassert>
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int n, m;
vector<set<int>> inedge, outedge;
vector<int> res;
int nsel = 0;

bool HasCircle() {
    vector<int> flag(n, 0);
    while (1) {
        int ptr = 0;
        while (!(ptr >= n || (inedge[ptr].size() == 0 && flag[ptr] == 0)))  {
            ptr++;
        }
        if (ptr >= n) {
            break;
        }

        assert(flag[ptr] == 0);
        nsel++;
        flag[ptr] = 1;
        res.push_back(ptr);

        for (set<int>::iterator it = outedge[ptr].begin(); it != outedge[ptr].end(); it++) {
            inedge[*it].erase(ptr);
        }
    }

    if (nsel == n) {
        return false;
    } else {
        return true;
    }
}

int main() {
    cin >> n >> m;
    inedge = outedge = vector<set<int>>(n);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        outedge[v1].insert(v2);
        inedge[v2].insert(v1);
    }
    if (HasCircle()) {
        cout << "No" << endl;
        printf("%d", n - nsel);
    } else {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                printf(" ");
            }
            printf("%d", res[i]);
        }
    }
    return 0;
}