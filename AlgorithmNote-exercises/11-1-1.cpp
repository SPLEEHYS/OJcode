#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

typedef long long LL;

LL n;
vector<LL> vec;

LL Fib(LL n) {
    if (vec[n] != -1) {
        return vec[n];
    } else {
        vec[n] = ((Fib(n - 1) % 10007) + (Fib(n - 2) % 10007)) % 10007;
        return vec[n];
    }
}

int main() {
    cin >> n;
    vec = vector<LL>(n + 1, -1);
    vec[1] = 1;
    vec[2] = 1;
    cout << Fib(n);
    return 0;
}