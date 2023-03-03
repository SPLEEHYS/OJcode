// https://www.noobdream.com/DreamJudge/Issue/page/1558/
#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int upb = sqrt(1.0 * m), cnt = 0;
        
        for (int i = 1; i <= upb; i++) {  
            if ((m % i == 0) && (m / i <= n)) {
                cnt += 2;
            }
        }
        if (upb * upb == m) {
            cnt--;
        }

        printf("%d\n", cnt);
    }
    return 0;
}