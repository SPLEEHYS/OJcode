#define INF 0x3fffffff
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

typedef struct node {
    pair<int, int> val;
    vector<int> next;
    friend bool operator < (node x1, node x2) {
        return x1.val.first  < x2.val.first && 
               x1.val.second < x2.val.second;
    }
    friend bool operator > (node x1, node x2) {
        return x1.val.first  > x2.val.first &&
               x1.val.second > x2.val.second;
    }
} node;

int n;
vector<node> vec;
vector<int> maxdis;

int dp(int x) {
    if (maxdis[x] != -INF) {
        return maxdis[x];
    }
    if (vec[x].next.size() == 0) {
        maxdis[x] = 1;
        return maxdis[x];
    }

    int rec = -INF;
    for (int i = 0; i < vec[x].next.size(); i++) {
        rec = max(rec, dp(vec[x].next[i]) + 1);
    }
    maxdis[x] = rec;
    return maxdis[x];
}

int main() {
    cin >> n;
    vec = vector<node>(n);
    maxdis = vector<int>(n, -INF);
    for (int i = 0; i < n; i++) {
        int x1, x2;
        scanf("%d %d", &vec[i].val.first, &vec[i].val.second);
        if (vec[i].val.first > vec[i].val.second) {
            swap(vec[i].val.first, vec[i].val.second);
        }
        for (int j = 0; j < i; j++) {
            if (vec[j] < vec[i]) {
                vec[j].next.push_back(i);
            } else if (vec[j] > vec[i]){
                vec[i].next.push_back(j);
            }
        }
    }

    int rec = -INF;
    for (int i = 0; i < n; i++) {
        rec = max(rec, dp(i));
    }
    cout << rec;
    return 0;
}