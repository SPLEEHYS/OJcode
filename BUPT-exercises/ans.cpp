// https://www.noobdream.com/DreamJudge/Issue/page/1489/
// 假设第10000个发财数不超过_MAX
#define _MAX 340000
#define FORT_MAX 10001
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n, t;
vector<int> isPrime(_MAX, 1), mem(_MAX, -1), pri, fort;

void PrimeBuild() { // 素数筛求素数
    for (int i = 2; i < isPrime.size(); i++) {
        if (isPrime[i] == 0) {
            continue;
        } else {
            pri.push_back(i);
        }
        for (int k = 2; i * k < _MAX; k++) {
            isPrime[i * k] = 0;
        }
    }
}

int dfs(int x) { // 计算x能被几个素数整除
	if (mem[x] != -1) { // 记忆化搜索
		return mem[x];
	}
	if (isPrime[x] == 1) { 
		mem[x] = 1;
		return mem[x];
	}

	for (int i = 0; i < pri.size(); i++) {
		if (x % pri[i] == 0) { 
			mem[x] = 1 + dfs(x / pri[i]);
			if (mem[x] >= 8) {
				fort.push_back(x);
			}
			return mem[x];
		}
	}
	exit(-1); // 任何一个数都能分解成若干个素数相乘，因此必能找到一个被整除
}

void FortBuild() {
	int x = 256;
	while (fort.size() < FORT_MAX) {
		dfs(x++);
	}
	return;
}

int main() {
    cin >> t;
    PrimeBuild();
    FortBuild();
    while (t--) {
        cin >> n;
        cout << fort[n - 1] << endl;
    }
    return 0;
}