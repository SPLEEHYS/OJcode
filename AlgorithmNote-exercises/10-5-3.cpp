#define INF 0x3fffffff
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, mincost = INF;
int gra[100][100];

void Prim() {
    vector<int> min_dis(n, INF);
    vector<int> inset(n, 0);
    int nsel = 0, acc = 0;
    min_dis[0] = 0;
    while (1) {
        int minval = INF - 1, ptr = -1;
        for (int i = 0; i < n; i++) {
            if (inset[i] == 0 && minval > min_dis[i]) {
                minval = min_dis[i];
                ptr = i;
            }
        }
        if (ptr == -1) {
            break;
        }

        inset[ptr] = 1;
        acc += minval;
        nsel++;

        for (int i = 0; i < n; i++) {
            if (min_dis[i] > gra[ptr][i] && inset[i] == 0) {
                min_dis[i] = gra[ptr][i];
            }
        }
    }
    mincost = acc;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &gra[i][j]);
        }
    }
    Prim();
    cout << mincost;
    return 0;
}