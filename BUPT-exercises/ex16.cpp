#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> isPrime(n, 1), res;
        for (int i = 2; i < n; i++) {
            if (!isPrime[i]) {
                continue;
            }
            if (i % 10 == 1) {
                res.push_back(i);
            }
            for (int k = 2; i * k < n; k++) {
                isPrime[i * k] = 0;
            }
        }
        for (int i = 0; i < res.size(); i++) {
            if (i != 0) {
                printf(" ");
            }
            printf("%d", res[i]);
        }
        if (res.size() == 0) {
            printf("-1");
        }
        printf("\n");
    }
    return 0;
}
