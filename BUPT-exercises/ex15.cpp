// https://www.noobdream.com/DreamJudge/Issue/page/1177/
#include <cassert>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
    vector<int> vec(n , 0);
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
        mp[vec[i]]++;
    }

    for (int i = 0; i < vec.size(); i++) {
        assert(mp[vec[i]] != 0);
        if (mp[vec[i]] == 1) {
            printf("BeiJu\n");
        } else {
            printf("%d\n", mp[vec[i]] - 1);
        }
        
    }
    }
    return 0;
}