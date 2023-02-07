#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

int n;
vector<int> preorder, inorder, res;

void postrav(int prelo, int prehi, int inlo, int inhi) {
    if (prelo > prehi) {
        assert(inlo > inhi);
        return;
    }

    int root = preorder[prelo], rtind = inlo;
    while (inorder[rtind] != root) {
        rtind++;
        assert(rtind >= 0 && rtind < n);
    }
    int leftlen = rtind - inlo;

    postrav(prelo + 1, prelo + leftlen, inlo, rtind - 1);
    postrav(prelo + leftlen + 1, prehi, rtind + 1, inhi);
    res.push_back(root);
}

int main() {
    cin >> n;
    preorder = inorder = vector<int>(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
        inorder[i] = preorder[i];
    }
    sort(inorder.begin(), inorder.end());

    postrav(0, n - 1, 0, n - 1);
    for (int i = 0; i < res.size(); i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", res[i]);
    }

    return 0;
}