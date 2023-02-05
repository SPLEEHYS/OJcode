#include<cstdio>
#include<iostream>
#include<queue>
#include<queue>
using namespace std;

typedef pair<int, int> node;

int n, head = 0;
vector<node> child;

bool isCompleteTree() {
    queue<int> que;
    que.push(head);
    int tag = 0;
    while (!que.empty()) {
        int capas = que.size();
        while (capas--) {
            int outelem = que.front();
            que.pop();
            if (outelem != -1 && tag == 1) {
                return false;
            }
            if (outelem == -1) {
                tag = 1;
                continue;
            }
            que.push(child[outelem].first);
            que.push(child[outelem].second);
        }
    }
    return true;
}

int main() {
    cin >> n;
    child = vector<node>(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &child[i].first, &child[i].second);
    }
    isCompleteTree() == true ? cout << "Yes" : cout << "No";
    return 0;
}