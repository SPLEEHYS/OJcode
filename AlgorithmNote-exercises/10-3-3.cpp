#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<cassert>
using namespace std;

int n, m;
vector<int> vis;
vector<set<int>> inedge; 
vector<set<int>> outedge;

bool HasCircle() {
    int cnt = 0;
    while (cnt < n) {
        int ind = 0;
        while (!(vis[ind] == 0 && inedge[ind].size() == 0)) {
            ind++;
            if (ind >= inedge.size()) {
                return true;
            }
        }

        vis[ind] = 1;
        cnt++;

        for (set<int>::iterator it = outedge[ind].begin(); it != outedge[ind].end(); it++) {
            assert(inedge[*it].find(ind) != inedge[*it].end());
            inedge[*it].erase(ind);
        }
    }
    return false;
}

int main () {
    cin >> n >> m;
    vis = vector<int>(n, 0);
    inedge = outedge = vector<set<int>>(n);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        outedge[v1].insert(v2);
        inedge[v2].insert(v1);
    }

    HasCircle() == true ? cout << "Yes" : cout << "No";
    return 0;
}