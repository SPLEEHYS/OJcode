#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

typedef pair<int, int> node;

int n, head = 0;
vector<node> child;

bool isFullTree() {
    queue<int> que;
    que.push(head);
    int lawyer = 1;
    while (!que.empty()) {
        int capas = que.size();
        if (capas != pow(2, lawyer - 1)) {
            return false;
        }
        while (capas--) {
            int outelem = que.front();
            que.pop();
            
            if (child[outelem].first != -1) {
                que.push(child[outelem].first);
            }
            if (child[outelem].second != -1) {
                que.push(child[outelem].second);
            }
        }
        lawyer++;
    }
    return true;
}

int main() {
    cin >> n;
    child = vector<node>(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &child[i].first, &child[i].second);
    }
    isFullTree() == true ? cout << "Yes": cout << "No";

    return 0;
}