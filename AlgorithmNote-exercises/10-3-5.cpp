#define INF 0x3fffffff

#include<queue>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n, m, k, s;
vector<int> dis;
vector<vector<int>> gra;

void BFS() {
    vector<int> vis = vector<int>(n, 0);
    queue<int> que;
    int lawyer = 0;
    que.push(s);
    vis[s] = 1;
    while (!que.empty()) {
        int capas = que.size();
        while (capas--) {
            int outelem = que.front();
            que.pop();
            dis[outelem] = lawyer;
            for (int i = 0; i < gra[outelem].size(); i++) {
                int newv = gra[outelem][i];
                if (vis[newv] == 0) {
                    que.push(newv);
                    vis[newv] = 1;
                }
            }   
        }
        lawyer++;
    }
}

int main() {
    cin >> n >> m >> s >> k;
    dis = vector<int>(n, INF);
    gra = vector<vector<int>>(n);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        gra[v1].push_back(v2);
    }

    BFS();

    int cnt = 0;
    for (int i = 0; i < dis.size(); i++) {
        if (dis[i] <= k) {
            cnt++;
        }
    }
    cout << cnt;

    return 0; 
}