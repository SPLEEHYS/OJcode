#define INF 0x3fffffff
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> vec, maxlen, pre;

int dfs(int x) {
    if (maxlen[x] != -INF) {
        return maxlen[x];
    }

    int rec = 1;
    pre[x] = x;

    for (int i = 0; i < x; i++) {
        if (vec[x] >= vec[i]) {
            int tmp = dfs(i) + 1;
            if (rec < tmp) {
                rec = tmp;
                pre[x] = i;
            }
        }
    }
    maxlen[x] = rec;
    return rec;
}

int main() {
    cin >> n;
    vec = maxlen = pre = vector<int>(n, -INF);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }

    maxlen[0] = 1;
    pre[0] = 0;

    int res = -INF;
    vector<int> trace;
    for (int i = 0; i < n; i++) {
        int tmp = dfs(i);
        if (res < tmp) {
            res = tmp;
            trace.clear();

            int ptr = i;
            while (ptr != pre[ptr]) {
                trace.push_back(vec[ptr]);
                ptr = pre[ptr];
            }
            trace.push_back(vec[ptr]);
        }
    }
    cout << res << endl;
    for (int i = trace.size() - 1; i >= 0; i--) {
        printf("%d", trace[i]);
        if (i != 0) {
            printf(" ");
        }
    }
    return 0;
}