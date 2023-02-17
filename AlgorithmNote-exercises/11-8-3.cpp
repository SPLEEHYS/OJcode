#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

typedef struct node {
    int zero = 0;
    int notzero = 0;
} node;

int n;

int main() {
    cin >> n;
    vector<node> num(n + 1);
    num[1].zero = 1;
    num[1].notzero = 9;
    for (int i = 2; i <= n; i++) {
        num[i].zero = num[i - 1].notzero;
        num[i].notzero = ((num[i - 1].zero + num[i - 1].notzero) * 9) % 10007;
    }
    cout << (num[n].zero + num[n].notzero) % 10007;
    return 0;
}