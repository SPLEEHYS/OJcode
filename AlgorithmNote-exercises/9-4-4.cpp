#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cassert>
using namespace std;

int n;
typedef pair<int, int> node;
map<int, node> child1, child2;
int head1, head2;

void Insert_BST(int &rt, int val, map<int, node> &child) {
    if (rt == -1) {
        rt = val;
        child[rt].first = -1;
        child[rt].second = -1;
        return;
    }
    if (val < rt) {
        Insert_BST(child[rt].first, val, child);
    } else {
        Insert_BST(child[rt].second, val, child);
    }
    return;
}

bool isEqualTree() {
    queue<int> que1, que2;
    que1.push(head1);
    que2.push(head2);

    while (!que1.empty()) {
        int capas = que1.size();
        assert(que1.size() == que2.size());

        while (capas--) {
            int outelem1 = que1.front();
            int outelem2 = que2.front();
            que1.pop();
            que2.pop();

            if (outelem1 != outelem2) {
                return false;
            }
            if (outelem1 == -1) {
                continue;
            }

            que1.push(child1[outelem1].first);
            que1.push(child1[outelem1].second);

            que2.push(child2[outelem2].first);
            que2.push(child2[outelem2].second);
        }
    }
    return true;
}

int main() {
    cin >> n;

    scanf("%d", &head1);
    child1[head1].first = -1;
    child1[head1].second = -1;

    for (int i = 1; i < n; i++) {
        int inpu;
        scanf("%d", &inpu);
        Insert_BST(head1, inpu, child1);
    }

    scanf("%d", &head2);
    child2[head2].first = -1;
    child2[head2].second = -1;

    for (int i = 1; i < n; i++) {
        int inpu;
        scanf("%d", &inpu);
        Insert_BST(head2, inpu, child2);
    }

    isEqualTree() == true ? cout << "Yes" : cout << "No";


    return 0;
}
