#include<cstdio>
#include<iostream>
#include<vector>
#include<cassert>
#include<cmath>
using namespace std;

vector<int> heap;

int Lchild(int cur) {
    // 返回- 1 表示 cur 无左孩子
    int res = cur * 2 + 1;
    if (res < heap.size()) {
        return res;
    } else {
        return -1;
    }
}

int Rchild(int cur) {
    // 返回- 1 表示 cur 无右孩子
    int res = cur * 2 + 2;
    if (res < heap.size()) {
        return res;
    } else {
        return -1;
    }
}

int MAX_ind(int x1_ind, int x2_ind) {
    // 返回大的索引
    if (x1_ind == -1) {
        return x2_ind;
    }
    if (x2_ind == -1) {
        return x1_ind;
    }
    if (heap[x1_ind] > heap[x2_ind]) {
        return x1_ind;
    } else {
        return x2_ind;
    }
}

void adjust(int cur) {
    if (heap.size() == 0) {
        return;
    }
    int val = heap[cur], ptr = cur;
    int lchild = Lchild(ptr);
    int rchild = Rchild(ptr);
    while (!(lchild == -1 && rchild == -1)) {
        int max_ind = MAX_ind(lchild, rchild);
        if (val < heap[max_ind]) {
            heap[ptr] = heap[max_ind];
            ptr = max_ind;
            lchild = Lchild(ptr);
            rchild = Rchild(ptr);
        } else {
            break;
        }
    }
    heap[ptr] = val;
}

int main() {
    int n;
    cin >> n;
    heap = vector<int>(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &heap[i]);
    }

    for (int i = (n - 1) / 2; i >= 0; i--) {
        adjust(i);
    }

    vector<int> res;
    while (!heap.empty()) {
        adjust(0);
        res.push_back(heap[0]);
        swap(heap[0], heap[heap.size() - 1]);
        heap.erase(heap.begin() + heap.size() - 1);
    }

    for (int i = res.size() - 1; i >= 0; i--) {
        if (i != res.size() - 1) {
            printf(" ");
        }
        printf("%d", res[i]);
    }

    return 0;
}