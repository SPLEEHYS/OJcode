#include<cassert>
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }
    priority_queue<int, vector<int>, greater<int>> que(vec.begin(), vec.end());
    int res = (n > 1) ? 0: vec[0];
    while (!(que.size() == 1)) {
        int x1 = que.top();
        que.pop();
        int x2 = que.top();
        assert(!que.empty());
        que.pop();
        res += x1 + x2;
        que.push(x1 + x2);
    }
    cout << res;
    return 0;
}