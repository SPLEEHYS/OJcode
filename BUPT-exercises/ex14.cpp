// https://www.noobdream.com/DreamJudge/Issue/page/1062/
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<vector<int>> vec(n, vector<int>(n, 1));
        if (n >= 1) {
            cout << 1 << '\n';
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (!(j == 0 || j == i)) {
                    vec[i][j] = vec[i - 1][j - 1] + vec[i - 1][j];
                }
                printf("%d", vec[i][j]);
                if (j != i) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}