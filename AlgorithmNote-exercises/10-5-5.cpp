#define INF 0x3fffffff
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, mincost = INF;
int gra[100][100];
vector<int> min_dis(100, INF);
vector<int> inset(100, 0);

void Prim() {
    int nsel = 0, acc = 0;
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
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &gra[i][j]);
        }
    }

    for (int i = 0; i < k; i++) {
        int inpu;
        scanf("%d", &inpu);
        min_dis[inpu] = 0;
    }

    Prim();
    cout << mincost;

    return 0;
}