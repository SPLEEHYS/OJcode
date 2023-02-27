// https://www.noobdream.com/DreamJudge/Issue/page/1560/
#define _MAX (1e9 + 1)
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

vector<int64_t> square, cube;

int BinSearch(vector<int64_t> &vec, int val) {
    int lo = 0, hi = vec.size();
    while (lo != hi) {
        int mid = (lo + hi) / 2;
        vec[mid] > val ? hi = mid : lo = mid + 1;
    }
    assert(lo == hi);
    return lo;
}

int main() {
    for (int64_t i = 1; i * i <= _MAX; i++) {
        square.push_back(i * i);
    }
    for (int64_t i = 1; i * i * i <= _MAX; i++) {
        int64_t val = i * i * i;
        if (square[BinSearch(square, val) - 1] == val) {
            cube.push_back(val);
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int inpu;
        scanf("%d", &inpu);
        printf("%d\n", BinSearch(cube, inpu));
    }

    return 0;
}