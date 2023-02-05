#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

typedef pair<int, int> node;

int n, head = 0;
vector<node> child;

void LeftView() {
    queue<int> que;
    que.push(head);

    while (!que.empty()) {
        int capas = que.size();
        for (int i = 0; i < capas; i++) {
            int outelem = que.front(); que.pop();
            if (outelem == -1) {
                continue;
            }
            if (i == 0) {
                if (outelem != head) {
                    printf(" ");
                }
                printf("%d", outelem);
            }

            assert(outelem >= 0 && outelem < n);

            if (child[outelem].first != -1) {
                que.push(child[outelem].first);
            }
            if (child[outelem].second != -1) {
                que.push(child[outelem].second);
            }
        }
    }
}

int main() {
    cin >> n;
    child = vector<node>(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &child[i].first, &child[i].second);
    }
    LeftView();

    return 0;
}